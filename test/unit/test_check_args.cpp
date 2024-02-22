#include "process.h"
#include "gtest/gtest.h"

extern "C"
{
#include "pipex.h"
#include "utils.h"
}

// static char *convert_const_char_to_void(const char *str) {
//   const char *const_element = static_cast<const char *>(str);
//   char *element = const_cast<char *>(const_element);
//
//   return (element);
// }

// TEST(exit_errno_msg, SampleMsg) {
// 	char *msg = convert_const_char_to_void("hello");
// 	EXPECT_EXIT(exit_errno_msg(msg), ::testing::ExitedWithCode(42), "hello\n");
// }

// TEST(exec_process, SampleArg)
// {
// 	const char	*cmd = "uname -n";
//
// 	EXPECT_EXIT(exec_process(cmd), ::testing::ExitedWithCode(0),
// 		"XLIJFELKNIX.local\n");
// }

TEST(_create_cmd_full_path, Partial_Path)
{
	const char	*cmd = "ls";
	const char	*ans = "/bin/ls";

	EXPECT_STREQ(_create_cmd_full_path(cmd), ans);
}

TEST(_create_cmd_full_path, Partial_Path1)
{
	const char	*cmd = "uname";
	const char	*ans = "/usr/bin/uname";

	EXPECT_STREQ(_create_cmd_full_path(cmd), ans);
}
