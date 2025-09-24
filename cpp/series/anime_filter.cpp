#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// ===== Цветовая квантизация через K-means =====
Mat colorQuantization(const Mat& img, int k)
{
    Mat samples(img.rows * img.cols, 3, CV_32F);
    for (int y = 0; y < img.rows; ++y) {
        for (int x = 0; x < img.cols; ++x) {
            for (int z = 0; z < 3; ++z) {
                samples.at<float>(y + x * img.rows, z) = img.at<Vec3b>(y, x)[z];
            }
        }
    }

    Mat labels, centers;
    kmeans(samples, k, labels,
        TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 1.0),
        3, KMEANS_PP_CENTERS, centers);

    Mat result(img.size(), img.type());
    for (int y = 0; y < img.rows; ++y) {
        for (int x = 0; x < img.cols; ++x) {
            int idx = labels.at<int>(y + x * img.rows, 0);
            result.at<Vec3b>(y, x)[0] = saturate_cast<uchar>(centers.at<float>(idx, 0));
            result.at<Vec3b>(y, x)[1] = saturate_cast<uchar>(centers.at<float>(idx, 1));
            result.at<Vec3b>(y, x)[2] = saturate_cast<uchar>(centers.at<float>(idx, 2));
        }
    }
    return result;
}

// ===== Маска контуров =====
Mat getEdgeMask(const Mat& imgGray)
{
    Mat blurred;
    medianBlur(imgGray, blurred, 7);
    Mat edges;
    adaptiveThreshold(blurred, edges, 255,
        ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY,
        9, 2);
    return edges;
}

// ===== Anime фильтр =====
Mat animeize(const Mat& src, int colorK = 24, int bilateralRepeats = 3)
{
    Mat img;
    src.copyTo(img);

    // ↓ Уменьшаем для ускорения (опционально)
    Mat small;
    pyrDown(img, small);

    // ↓ Несколько проходов bilateralFilter
    Mat bf = small.clone();
    Mat temp;
    for (int i = 0; i < bilateralRepeats; ++i) {
        bilateralFilter(bf, temp, 9, 75, 75);
        temp.copyTo(bf);
    }

    // ↓ Доп. сглаживание / сегментация
    Mat meanShift;
    pyrMeanShiftFiltering(bf, meanShift, 16, 40, 1);

    // ↓ Возвращаем в исходный размер
    Mat up;
    pyrUp(meanShift, up, img.size());

    // ↓ Квантизация цветов
    Mat quant = colorQuantization(up, colorK);

    // ↓ Контуры
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    Mat edges = getEdgeMask(gray);

    // Инвертируем, чтобы линии были чёрными
    Mat edges_inv;
    bitwise_not(edges, edges_inv);
    Mat edges_inv_color;
    cvtColor(edges_inv, edges_inv_color, COLOR_GRAY2BGR);

    // ↓ Наложение контуров на квантизованное изображение
    edges_inv_color.convertTo(edges_inv_color, CV_32F, 1.0 / 255.0);
    Mat quant_f;
    quant.convertTo(quant_f, CV_32F);
    Mat multiplied = quant_f.mul(edges_inv_color);

    Mat finalResult;
    multiplied.convertTo(finalResult, CV_8U);

    return finalResult;
}

// ===== MAIN =====
int main(int argc, char** argv)
{
    cout << "Anime filter (OpenCV C++)\n";
    cout << "Usage:\n";
    cout << "  " << argv[0] << " image.jpg\n";
    cout << "  " << argv[0] << " camera   (to use webcam)\n\n";

    VideoCapture cap;
    Mat img;
    bool useCamera = false;

    if (argc >= 2 && string(argv[1]) == "camera") {
        useCamera = true;
        cap.open(0);
        if (!cap.isOpened()) {
            cerr << "Failed to open camera\n";
            return -1;
        }
    } else if (argc >= 2) {
        img = imread(argv[1]);
        if (img.empty()) {
            cerr << "Failed to open image: " << argv[1] << "\n";
            return -1;
        }
    } else {
        cerr << "Please provide image path or 'camera'.\n";
        return -1;
    }

    if (useCamera) {
        cout << "Press ESC to quit\n";
        Mat frame;
        while (true) {
            cap >> frame;
            if (frame.empty())
                break;
            Mat out = animeize(frame, 16, 3);
            imshow("Anime Filter - Camera", out);
            int key = waitKey(1);
            if (key == 27)
                break; // ESC
        }
    } else {
        Mat out = animeize(img, 24, 3);
        imshow("Original", img);
        imshow("Anime Filter", out);
        cout << "Press any key to save output as 'anime_result.png' or ESC to exit without saving.\n";
        int key = waitKey(0);
        if (key != 27) {
            imwrite("anime_result.png", out);
            cout << "Saved: anime_result.png\n";
        }
    }

    return 0;
}
