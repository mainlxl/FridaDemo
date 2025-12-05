/*
 * Simple MD5 implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// 新的用户友好接口
// 计算字符串的MD5哈希，结果存入output_buffer(至少33字节)
// 返回: 0=成功, -1=失败
int md5_string(const char *input, char *output_buffer);

#ifdef __cplusplus
}
#endif