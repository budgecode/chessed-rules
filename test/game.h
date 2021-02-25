#pragma once

#include <iostream>

#include <catch2/catch.hpp>

#include "../include/game.h"

using namespace chessed::chess;

/**
 * Test that game starts with correct state
 * Test that white goes first
 * 
 * Start testing moves
 **/

TEST_CASE("Index operators work", "[game]")
{
    Game game;

    REQUIRE(game[0] == WhiteRook);
    REQUIRE(game["a1"] == WhiteRook);
    REQUIRE(game(0, 0) == WhiteRook);
    REQUIRE(game[63] == BlackRook);
    REQUIRE(game["h8"] == BlackRook);
    REQUIRE(game(7, 7) == BlackRook);
}

TEST_CASE("Ensure moves are counted correctly", "[game]")
{
    Game game;
    Move info;
    bool valid = game.move("a2", "a3", info);
    REQUIRE(valid);
    REQUIRE(game.get_half_moves() == 1);
    REQUIRE(game.get_move_num() == 1);

    valid = game.move("h7", "h6", info);
    REQUIRE(valid);
    REQUIRE(game.get_half_moves() == 2);
    REQUIRE(game.get_move_num() == 2);

    valid = game.move("a3", "a4", info);
    REQUIRE(valid);
    REQUIRE(game.get_half_moves() == 3);
    REQUIRE(game.get_move_num() == 2);
}

TEST_CASE("Ensure turn changes on each move", "[game]")
{
    Game game;
    
    REQUIRE(game.get_turn() == 0);

    Move info;
    bool valid = game.move("a2", "a3", info);
    REQUIRE(valid);
    REQUIRE(game.get_turn() == 1);
    
    valid = game.move("h7", "h6", info);
    REQUIRE(valid);
    REQUIRE(game.get_turn() == 0);
    
    valid = game.move("a3", "a4", info);
    REQUIRE(valid);
    REQUIRE(game.get_turn() == 1);
    
}

TEST_CASE("Ensure player can't move out of turn", "[game]")
{
    Game game;
    Move info;
    bool valid = game.move("a2", "a3", info);
    REQUIRE(valid);

    valid = game.move("a3", "a4", info);
    REQUIRE_FALSE(valid);
    
    valid = game.move("a3", "a4", info);
    REQUIRE_FALSE(valid);
    
}

TEST_CASE("Ensure pawns move correctly", "[game]")
{
    SECTION("pawn moves forward to empty spot")
    {
        Game game;
        Move info;
        bool valid = game.move("a2", "a3", info);
        REQUIRE(valid);

        valid = game.move("h7", "h6", info);
        REQUIRE(valid);
    }
    
}