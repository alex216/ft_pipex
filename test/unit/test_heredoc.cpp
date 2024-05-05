#include "gtest/gtest.h"

extern "C"
{
#include "here_doc.h"
}

TEST(is_heredoc, WrongStr)
{
	const char *argv[] = {"./pipex", "cat", NULL};
	int res = is_heredoc(argv);
	EXPECT_FALSE(res);

	const char *argv1[] = {"./pipex", "here", NULL};
	int res1 = is_heredoc(argv1);
	EXPECT_FALSE(res1);

	const char *argv2[] = {"./pipex", "here_doca", NULL};
	int res2 = is_heredoc(argv2);
	EXPECT_FALSE(res2);
}

TEST(is_heredoc, CorrectStr)
{
	const char *argv[] = {"./pipex", "here_doc", NULL};
	int res = is_heredoc(argv);
	EXPECT_TRUE(res);
}
