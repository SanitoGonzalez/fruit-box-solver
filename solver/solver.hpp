#pragma once

#include <board.hpp>

#include <format>
#include <vector>

struct Drag {
    size_t x, y;
};

struct Match {
    Position pos;
    Drag drag;
};

std::vector<Match> find_matches(const Board &board);
void find_match(const Board &board, std::vector<Match>& matches, Position position, Drag drag);

inline int solve(const Board &board) {
    auto matches {find_matches(board)};

    return 0;
}

inline std::vector<Match> find_matches(const Board &board) {
    std::vector<Match> matches;

    for (size_t y = 0; y < Board::Height; ++y) {
        for (size_t x = 0; x < Board::Width; ++x) {
            find_match(board, matches, Position{x, y}, Drag{0, 0});
        }
    }

    return matches;
}

inline void find_match(
    const Board &board,
    std::vector<Match>& matches,
    const Position position,
    const Drag drag) {
    int sum{0};
    for (size_t y = position.y; y <= position.y + drag.y; ++y)
        for (size_t x = position.x; x <= position.x + drag.x; ++x)
            sum += board.data()[y][x];

    if (sum == 10) {
        matches.push_back({position, drag});
        return;
    }
    if (sum > 10)
        return;

    // Drag right
    if (position.x + drag.x + 1 < Board::Width)
        find_match(board, matches, position, Drag{drag.x + 1, drag.y});

    // Drag down
    if (position.y + drag.y + 1 < Board::Height)
        find_match(board, matches, position, Drag{drag.x, drag.y + 1});
}
