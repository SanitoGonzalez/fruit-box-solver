#include <board.hpp>
#include <solver.hpp>

#include <iostream>

int main() {
    const auto board{Board::generate()};
    board.display();

    Solver solver{};
    std::cout << solver.solve(board) << std::endl;
}
