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
//   return (element); }

TEST(_join_dir_base, Valid_command_basename) {
	const char	*path_list[] = {"/bin", "/usr/bin", NULL};
	const char	*cmd = "ls";
	EXPECT_STREQ(_join_dir_base(path_list, cmd), "/bin/ls");
};

TEST(_join_dir_base, Invalid_command_basename) {
	const char	*path_list[] = {"/bin", "/usr/bin", NULL};
	const char	*cmd = "cmd42";
	EXPECT_STREQ(_join_dir_base(path_list, cmd), NULL);
};

TEST(_search_path_list, Path_exist) {
	const char	*env_list[] = {"PAGER=less", "PATH=/bin:/usr/bin", NULL};
	EXPECT_STREQ(_search_path_list(env_list), env_list[1]);
};

#include <cstdlib>
TEST(_search_path_list, Path_doesnt_exist) {
    unsetenv("PATH");
	const char	*env_list[] = {"PAGER=less", NULL};
	EXPECT_STREQ(_search_path_list(env_list), NULL);
};

TEST(_return_entire_path, Full_path)
{
	const char	*path_list[] = {"/bin/ls", "/bin/vim", NULL};
	const char	*cmd = "/bin/ls";
	const char	*ans = "/bin/ls";

	EXPECT_STREQ(_return_entire_path(cmd, path_list), ans);
}
