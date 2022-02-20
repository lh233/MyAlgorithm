/*
 * @Descripttion: 描述断言的宏定义
 * @version: 
 * @Author: linhao
 * @Date: 2022-02-20 10:17:39
 * @LastEditors: linhao
 * @LastEditTime: 2022-02-20 10:35:17
 */
#define ASSER(condition, message) {         \
    if(!(condition)) {                      \
        LogError("Assertion failed:",       \
            #condition, message);           \
        exit(EXIT_FAILURE);                 \
    }                                       \
}                                           \