#include "gtest/gtest.h"

extern "C"
{
#include "pipex.h"
#include "utils.h"
#include "process.h"
}

TEST(real_strchr, Test0) {
	const char	*str = "'123";
	char quote = '\'';

	EXPECT_STREQ(real_strchr(str, quote), &str[0]);
};

TEST(real_strchr, Test1) {
	const char	*str = "01'3";
	char quote = '\'';

	EXPECT_STREQ(real_strchr(str, quote), &str[2]);
};

TEST(real_strchr, Test2) {
	const char	*str = "012'";
	char quote = '\'';

	EXPECT_STREQ(real_strchr(str, quote), &str[3]);
};

TEST(real_strchr, Test0d) {
	const char	*str = "\"123";
	char quote = '"';

	EXPECT_STREQ(real_strchr(str, quote), &str[0]);
};

TEST(real_strchr, Test1d) {
	const char	*str = "01\"3";
	char quote = '"';

	EXPECT_STREQ(real_strchr(str, quote), &str[2]);
};

TEST(real_strchr, Test2d) {
	const char	*str = "012\"";
	char quote = '"';

	EXPECT_STREQ(real_strchr(str, quote), &str[3]);
};

TEST(real_strrchr, Test0) {
	const char	*str = "'123";
	char quote = '\'';

	EXPECT_STREQ(real_strrchr(str, quote), &str[0]);
};

TEST(real_strrchr, Test1) {
	const char	*str = "01'3";
	char quote = '\'';

	EXPECT_STREQ(real_strrchr(str, quote), &str[2]);
};

TEST(real_strrchr, Test2) {
	const char	*str = "012'";
	char quote = '\'';

	EXPECT_STREQ(real_strrchr(str, quote), &str[3]);
};

TEST(real_strrchr, Test0d) {
	const char	*str = "\"123";
	char quote = '"';

	EXPECT_STREQ(real_strrchr(str, quote), &str[0]);
};

TEST(real_strrchr, Test1d) {
	const char	*str = "01\"3";
	char quote = '"';

	EXPECT_STREQ(real_strrchr(str, quote), &str[2]);
};

TEST(real_strrchr, Test2d) {
	const char	*str = "012\"";
	char quote = '"';

	EXPECT_STREQ(real_strrchr(str, quote), &str[3]);
};
