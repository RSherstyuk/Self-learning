#pragma once

#include <iostream>
#include <queue>
#include <vector>

class Graph {
private:
  int V;                             // Количество вершин
  std::vector<std::vector<int>> adj; // Список смежности

public:
  /**
   * @brief Конструктор графа
   * @param ver Количество вершин в графе
   */
  Graph(int ver);

  /**
   * @brief Добавляет направленное ребро в граф
   * @param u Исходная вершина
   * @param v Целевая вершина
   */
  void addEdge(int u, int v);

  /**
   * @brief Выполняет топологическую сортировку графа
   * @return Вектор с вершинами в топологическом порядке
   * @note Возвращает пустой вектор если граф содержит цикл
   */
  std::vector<int> topologicalSort();

  // Удаляем конструктор копирования и оператор присваивания
  Graph(const Graph &) = delete;
  Graph &operator=(const Graph &) = delete;
};
