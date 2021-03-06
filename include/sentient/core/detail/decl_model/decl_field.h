#ifndef __SENTIENT_CORE_DETAIL_DECL_MODEL_DECL_FIELD_H__
#define __SENTIENT_CORE_DETAIL_DECL_MODEL_DECL_FIELD_H__

#include <sentient/core/pp_utils.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief determines how to declare a field
 */
#define ___SNT_PP_DECL_FIELD(...)             \
        ___SNT_PP_CAT_2(                      \
            ___SNT_PP_DECL_FIELD_,            \
            ___SNT_PP_COUNT_ARGS __VA_ARGS__  \
        ) __VA_ARGS__

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief declares a field with an expression
 */
#define ___SNT_PP_DECL_FIELD_1(MODEL_EXTRA_ATTR) \
        ___SNT_PP_DECL_FIELD_1_IMPL(MODEL_EXTRA_ATTR)
#define ___SNT_PP_DECL_FIELD_1_IMPL(MODEL_EXTRA_ATTR) \
        ___SNT_PP_FOREACH(MODEL_EXTRA_ATTR)

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief common field
 */
#define ___SNT_PP_DECL_FIELD_2(TYPE, NAME) \
        ___SNT_PP_DECL_FIELD_2_IMPL(TYPE, NAME)
#define ___SNT_PP_DECL_FIELD_2_IMPL(TYPE, NAME) \
        TYPE NAME ;

#define ___SNT_PP_DECL_FIELD_3(TYPE, NAME, KEYWORD) \
        ___SNT_PP_DECL_FIELD_3_IMPL(TYPE, NAME, KEYWORD)
#define ___SNT_PP_DECL_FIELD_3_IMPL(TYPE, NAME, KEYWORD)         \
        ___SNT_PP_IF_ELSE(___SNT_PP_HAS_COMMA(KEYWORD))          \
        (                                                        \
                                                                 \
        )                                                        \
        (                                                        \
            ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(SNT_PTR, KEYWORD)) \
            (                                                    \
                TYPE * NAME ;                                    \
            )                                                    \
            (                                                    \
                                                                 \
            )                                                    \
        )
        
/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief array or bit field
 */
#define ___SNT_PP_DECL_FIELD_4(TYPE, NAME, KEYWORD, SIZE) \
        ___SNT_PP_DECL_FIELD_4_IMPL(TYPE, NAME, KEYWORD, SIZE)
#define ___SNT_PP_DECL_FIELD_4_IMPL(TYPE, NAME, KEYWORD, SIZE)         \
        TYPE NAME                                                      \
        ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(KEYWORD, SNT_ARRAY))         \
        (                                                              \
            ___SNT_PP_ARR(SIZE) ;                                      \
        )                                                              \
        (                                                              \
            ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(KEYWORD, SNT_BIT_FIELD)) \
            (                                                          \
                ___SNT_PP_BF(SIZE) ;                                   \
            )                                                          \
            ()                                                         \
        )

#define ___SNT_PP_DECL_FIELD_5(TYPE, NAME, KEYWORD, SIZE, ATTRIBUTES) \
        ___SNT_PP_DECL_FIELD_5_IMPL(TYPE, NAME, KEYWORD, SIZE, ATTRIBUTES)
#define ___SNT_PP_DECL_FIELD_5_IMPL(TYPE, NAME, KEYWORD, SIZE, ATTRIBUTES) \
        ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(KEYWORD, SNT_ARRAY))             \
        (                                                                  \
            ___SNT_PP_ARR(SIZE) ;                                          \
        )                                                                  \
        (                                                                  \
            ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(KEYWORD, SNT_BIT_FIELD))     \
            (                                                              \
                ___SNT_PP_BF(SIZE) ;                                       \
            )                                                              \
            ()                                                             \
        )

#define ___SNT_PP_PARSE_KEYWORDS(...) \
        ___SNT_PP_PARSE_KEYWORDS_IMPL(__VA_ARGS__)
#define ___SNT_PP_PARSE_KEYWORDS_IMPL(...)    \
        ___SNT_PP_FOREACH(                    \
            ___SNT_PP_PARSE_KEYWORDS_HANDLER, \
            __VA_ARGS__                       \
        )

#define ___SNT_PP_PARSE_KEYWORDS_HANDLER(KEYWORD) \
        ___SNT_PP_PARSE_KEYWORDS_HANDLER_IMPL(KEYWORD)
#define ___SNT_PP_PARSE_KEYWORDS_HANDLER_IMPL(KEYWORD) \
        ___SNT_PP_IF_ELSE()

#ifdef __cplusplus
}
#endif

#endif