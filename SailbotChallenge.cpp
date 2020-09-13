#include "pch.h"

/**
 * This C++ file is my submition for the Sailbot Coding Challenge. It contains two methods, BoundTo180() which forces any angle to lie between -180 to 180, 
 * IsAngleBetween() which determines if an angle lies between the acute angle between two others as well as unit tests using Google Test.
 * 
 * Thanks for considering my application!
 * 
 * @author Joshua Sam, 3rd year ELEC student.
 * @date September 13, 2020
 * 
 */


//Function Declarations
float BoundTo180(float angle);
bool IsAngleBetween(float first_angle, float middle_angle, float second_angle);

/**
 * UNIT TESTS for BoundTo180() , IsAngleBetween()
 */

TEST(Sailbot, BoundTo180Test)
{
	EXPECT_EQ(BoundTo180(360), 0);
    EXPECT_EQ(BoundTo180(270), -90);
    EXPECT_EQ(BoundTo180(-450), -90);
}

TEST(Sailbot, IsAngleBetweenTest) 
{
	ASSERT_TRUE(IsAngleBetween(-90,-180,110));
    ASSERT_FALSE(IsAngleBetween(-90, -180, 80));
}

/**
 * Bounds the provided angle between [-180, 180) degrees.
 * Ex. 360 becomes 0, 270 becomes -90, -450 becomes -90.
 * @param angle Input angle in degrees.
 * @return The bounded angle in degrees.
 */
float BoundTo180(float angle)
{
    float bounded_angle = angle;

    while (bounded_angle > 180) bounded_angle -= 360;

    while (bounded_angle < -180) bounded_angle += 360;

    return bounded_angle;
}

/**
 * Determines whether |middle_angle| is in the acute angle between the other two
bounding angles.
 * Note: Input angles are bounded to 180 for safety.
 * Ex. -180 is between -90 and 110 but not between -90 and 80.
 * @param first_angle First angle in degrees.
 * @param middle_angle Middle angle in degrees.
 * @param second_angle Second angle in degrees.
 * @return Whether |middle_angle| is between |first_angle| and |second_angle|
(exclusive).
 */
bool IsAngleBetween(float first_angle, float middle_angle, float second_angle)
{
    float larger_angle;
    float smaller_angle;

    //Convert all values to 0 degrees -> 360 degrees to make it less error prone
    if (first_angle < 0) first_angle += 360;
    if (middle_angle < 0) middle_angle += 360;
    if (second_angle < 0) second_angle += 360;

    //determine the larger and smaller angle
    if (first_angle > second_angle)
    {
        larger_angle = first_angle;
        smaller_angle = second_angle;
    }
    else
    {
        larger_angle = second_angle;
        smaller_angle = first_angle;
    }

    //Check for the two conditions where the middle angle lies between the other two bounding angles and return true
    if ((larger_angle - smaller_angle) < 180 && smaller_angle <= middle_angle <= larger_angle) return true;
    if ((larger_angle - smaller_angle) > 180 && smaller_angle >= middle_angle >= larger_angle) return true;

    //otherwise return false
    return false;

}