#include "gtest/gtest.h"

extern "C" {
#include "utils.h"
#include "pipex.h"
}

static char *convert_const_char_to_void(const char *str) {
  const char *const_element = static_cast<const char *>(str);
  char *element = const_cast<char *>(const_element);

  return element;
}

TEST(exit_errno_msg, SampleMsg) {
	char *msg = convert_const_char_to_void("hello");
	EXPECT_EXIT(exit_errno_msg(msg), ::testing::ExitedWithCode(42), "hello\n");
}
