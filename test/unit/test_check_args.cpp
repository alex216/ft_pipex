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

TEST(_join_dir_base, Defined_Path) {
	const char	*path_list[] = {"/bin", "/usr/bin", NULL};
	const char	*cmd = "ls";
	EXPECT_STREQ(_join_dir_base(path_list, cmd), "/bin/ls");
};

// TEST(_join_dir_base, Undefined_Path)
// {
//
// }

// TEST(_create_cmd_full_path, Partial_Path)
// {
// 	const char	*path_list[] = {"/bin/ls", "/bin/vim", NULL};
// 	const char	*cmd = "ls";
// 	const char	*ans = "/bin/ls";
//
// 	EXPECT_STREQ(_create_cmd_full_path(cmd, path_list), ans);
// }
//
// TEST(_create_cmd_full_path, Partial_Path1)
// {
// 	const char	*path_list[] = {"/bin/ls", "/bin/vim", "/usr/bin/uname", NULL};
// 	const char	*cmd = "uname";
// 	const char	*ans = "/usr/bin/uname";
//
// 	EXPECT_STREQ(_create_cmd_full_path(cmd ,path_list), ans);
// }
