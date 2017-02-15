#ifndef GRAPH_BROWSER_HPP
#define GRAPH_BROWSER_HPP

#include <curses.h>
#include <menu.h>

#include <deque>

#include <graph/graph.hpp>

class GraphBrowser {
public:

  static constexpr size_t TERM_MAX_X = 80;
  static constexpr size_t TERM_MAX_Y = 24;

  static constexpr int KEY_ESC = 27;
  static constexpr int KEY_LOWER_CASE_D = 100;
  static constexpr int KEY_LOWER_CASE_I = 105;
  static constexpr int KEY_UPPER_CASE_D = 68;
  static constexpr int KEY_UPPER_CASE_I = 73;

  static constexpr size_t window_height = TERM_MAX_Y-2;
  static constexpr size_t current_window_width = TERM_MAX_X/4;
  static constexpr size_t n_window_width = TERM_MAX_X/4;

  void static init();
  void static destroy();

  GraphBrowser(Graph<std::string>& g);
  ~GraphBrowser();

  void mainLoop();
  void setStartVertex(const std::string& s);

private:

  void updateCurrent(const std::string& s);
  void updateNeighbours();
  void addItems(const std::vector<std::string>& stringVector);
  void deleteElement(bool delete_node);

  MENU *menu_;
  WINDOW *current_win_, *n_win, * n_of_n_win_;
//   ITEM **items_;
  Graph<std::string>& graph_;

  std::deque<std::string> history_;
};

#endif // GRAPH_BROWSER_HPP
