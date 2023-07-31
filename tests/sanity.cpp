#include <gtest/gtest.h>

TEST(sanity, int_test) {
	EXPECT_EQ(1, 1);
}

TEST(sanity, float_test) {
	EXPECT_EQ(1.0, 1.0);
}

TEST(sanity, char_arr_test) {
	const char* str1 = "Hello";
	const char* str2 = "Hello";
	EXPECT_STREQ(str1, str2);
}
