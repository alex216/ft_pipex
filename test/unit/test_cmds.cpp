#include "gtest/gtest.h"

extern "C"
{
#include "pipex.h"
#include "utils.h"
#include "process.h"
}

TEST(return_entire_path, CmdWithSlash_NoF_OK)
{
	const char *envp[] = {"PATH=/bin:/usr/bin", NULL};
	const char *cmd = "/bin/cmd42";
	const char *err_msg = "bash: /bin/cmd42: No such file or directory";

	EXPECT_EXIT(return_entire_path(cmd, envp), ::testing::ExitedWithCode(127), err_msg);
}

TEST(return_entire_path, CmdWithSlash_EnvpIsNULL)
{
	const char *envp[] = {NULL};
	const char *cmd = "/bin/ls";
	const char *ans = "/bin/ls";

	EXPECT_STREQ(return_entire_path(cmd, envp), ans);
}

TEST(return_entire_path, CmdWithSlash_Ok)
{
	const char *envp[] = {"PATH=/bin:/usr/bin", NULL};
	const char *cmd = "ls";
	const char *ans = "/bin/ls";

	EXPECT_STREQ(return_entire_path(cmd, envp), ans);
}

TEST(return_entire_path, CmdWithoutSlash_EnvpIsNULL)
{
	const char *envp[] = {NULL};
	const char *cmd = "ls";
	const char *err_msg = "bash: ls: No such file or directory";

	EXPECT_EXIT(return_entire_path(cmd, envp), ::testing::ExitedWithCode(127), err_msg);
}

TEST(return_entire_path, CmdWithoutSlash_NoF_OK)
{
	const char *envp[] = {"PATH=/bin:/usr/bin", NULL};
	const char *cmd = "cmd42";
	const char *err_msg = "bash: cmd42: command not found";

	EXPECT_EXIT(return_entire_path(cmd, envp), ::testing::ExitedWithCode(127), err_msg);
}

TEST(return_entire_path, CmdWithoutSlash_OK)
{
	const char *envp[] = {"PATH=/bin:/usr/bin", NULL};
	const char *cmd = "ls";
	const char *ans = "/bin/ls";

	EXPECT_STREQ(return_entire_path(cmd, envp), ans);
}
