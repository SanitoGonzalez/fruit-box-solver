#pragma once

#include <board.hpp>

#include <vector>

std::vector<Pos> find_matches(const Board &board);

int solve(const Board &board) {
    auto matches {find_matches(board)};


    return 0;
}

std::vector<Pos> find_matches(const Board &board) {
    std::vector<Pos> matches;


    return matches;
}
