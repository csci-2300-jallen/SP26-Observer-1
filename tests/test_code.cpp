#include <catch2/catch_test_macros.hpp>
#include <string>

#include "Point2D.h"
#include "MovingPoint2D.h"

TEST_CASE("Point2D getText format matches expected") {
    Point2D p(1, 10);
    REQUIRE(p.getText() == "Point 2D(1, 10).");
}

TEST_CASE("MovingPoint2D moves correctly") {
    MovingPoint2D mp(0, 0);
    mp.moveVertically(10);
    mp.moveHorizontally(-10);

    REQUIRE(mp.getX() == -10);
    REQUIRE(mp.getY() == 10);
}

TEST_CASE("MovingPoint2D getText reflects updated position") {
    MovingPoint2D mp(0, 0);
    mp.moveVertically(10);
    mp.moveHorizontally(-10);

    // If you chose to override getText in MovingPoint2D:
    // REQUIRE(mp.getText() == "Moving Point 2D(-10, 10).");

    // If you chose NOT to override getText (inherits Point2D::getText):
    REQUIRE(mp.getText() == "Point 2D(-10, 10).");
}

