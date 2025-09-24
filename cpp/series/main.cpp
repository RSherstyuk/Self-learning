#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

Mat animeStyle(Mat src, int lineSize, int blurValue, int k)
{
    Mat gray, edges, dst;
    Mat blurred;

    // 1. Сглаживание изображения
    bilateralFilter(src, blurred, 9, blurValue, blurValue);

    // 2. Уменьшение цветовой палитры с помощью k-mean clustering
    Mat data = blurred.reshape(1, blurred.rows * blurred.cols);
    data.convertTo(data, CV_32F);
    vector<int> labels;
    Mat centers;
    kmeans(data, k, labels, TermCriteria(TermCriteria::MAX_ITER | TermCriteria::EPS, 10, 0.01), 3, KMEANS_PP_CENTERS, centers);
    Mat quantized = blurred.clone();

    for (int i = 0; i < 10; i++) {
        std::cout << i << "\n";
    }

    for (int i = 0; i < blurred.rows * blurred.cols; i++) {
        int cluster_idx = labels[i];
        quantized.at<Vec3b>(i / blurred.cols, i % blurred.cols) = centers.at<Vec3f>(cluster_idx);
    }

    // 3. Обнаружение границ
    cvtColor(quantized, gray, COLOR_BGR2GRAY);
    medianBlur(gray, gray, 5);
    adaptiveThreshold(gray, edges, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, lineSize, 2);
    cvtColor(edges, edges, COLOR_GRAY2BGR);

    // 4. Объединение границ и квантованного изображения
    bitwise_and(quantized, edges, dst);

    return dst;
}

int main()
{
    Mat src = imread("ava.jpg");
    if (src.empty()) {
        cout << "Ошибка загрузки изображения!" << endl;
        return -1;
    }

    Mat anime = animeStyle(src, 7, 5, 2); // Параметры можно настроить
    imwrite("anime_output.jpg", anime);

    return 0;
}
