#include "gtest/gtest.h"

extern "C"
{
#include "pipex.h"
#include "utils.h"
#include "process.h"
#include "parse_string.h"
}

TEST(parse_string, Normal_Split0)
{
	const char **res = parse_string("cat");

	EXPECT_STREQ(res[0], "cat");
	ASSERT_TRUE(res[1] == nullptr);
}

TEST(parse_string, Blank_char)
{
	const char **ans = parse_string("ls -l");
	EXPECT_STREQ(ans[0], "ls");
	EXPECT_STREQ(ans[1], "-l");
	ASSERT_TRUE(ans[2] == nullptr);

	const char **ans2 = parse_string("ls\t-l");
	EXPECT_STREQ(ans2[0], "ls");
	EXPECT_STREQ(ans2[1], "-l");
	ASSERT_TRUE(ans2[2] == nullptr);
}

// TEST(parse_string, BackSlash_22_special_charactor) {
//
// 	const char **res = parse_string("echo 'hello world'");
// 	EXPECT_STREQ(res[0], "echo");
// 	EXPECT_STREQ(res[1], "hello world");
// 	ASSERT_TRUE(res[2] == nullptr);
//
//   // const char **res = parse_string("\\~\\`\\#\\$\\*\\(\\)\\\\|\\,\\[\\]\\{\\}\\;\\'\"\\<\\>\\/\\?\\!");
//   //
//   // EXPECT_EQ(std::string(res[0]), std::string("~`#$*()\\|,[]{};'\"<>/?!"));
//   // EXPECT_EQ(res[1], nullptr);
// }
