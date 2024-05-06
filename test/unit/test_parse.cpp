#include "gtest/gtest.h"

extern "C"
{
#include "pipex.h"
#include "utils.h"
#include "xfork_exec.h"
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

TEST(parse_string, Quotation) {

	const char **res = parse_string("echo 'hello world'");
	EXPECT_STREQ(res[0], "echo");
	EXPECT_STREQ(res[1], "hello world");
	ASSERT_TRUE(res[2] == nullptr);

	const char **res1 = parse_string("echo 'hello ''world'");
	EXPECT_STREQ(res1[0], "echo");
	EXPECT_STREQ(res1[1], "hello world");
	ASSERT_TRUE(res1[2] == nullptr);

	// test str: [echo wendy\'s]
	const char **res2 = parse_string("echo wendy\\\'s");
	EXPECT_STREQ(res2[0], "echo");
	EXPECT_STREQ(res2[1], "wendy's");
	ASSERT_TRUE(res2[2] == nullptr);

	// test str: [\]
	const char **res3 = parse_string("\\\\");
	EXPECT_STREQ(res3[0], "\\"); // this is [\]
	ASSERT_TRUE(res3[1] == nullptr);

	// various input
	const char **res4 = parse_string("\\~\\`\\#\\$\\*\\(\\)\\\\|\\,\\[\\]\\{\\}\\;\\'\"\\<\\>\\/\\?\\!");
	EXPECT_STREQ(res4[0], "~`#$*()\\|,[]{};'\"<>/?!");
	ASSERT_TRUE(res4[1] == nullptr);
}
