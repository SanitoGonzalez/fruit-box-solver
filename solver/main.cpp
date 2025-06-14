#include <board.hpp>
#include <solver.hpp>

#include <iostream>

int main() {
    const auto board{Board::generate()};
    board.display();

    std::cout << solve(board) << std::endl;
}
