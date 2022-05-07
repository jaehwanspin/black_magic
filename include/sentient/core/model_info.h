#ifndef __SENTIENT_CORE_MODEL_INFO_H__
#define __SENTIENT_CORE_MODEL_INFO_H__

/**
 * @file model_info.h
 * @author Jin (jaehwanspin@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <sentient/core/types.h>

/**
 * @file define_model.h
 * @author Jin (jaehwanspin@gmail.com)
 * @brief defines a struct that describes the type(model)
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifdef __cplusplus
extern "C"
{
#endif

struct sentient_field_info;

struct sentient_model_info
{
    sentient_str8*              model_name;
    sentient_size               actual_size;
    sentient_size               fields_count;
    struct sentient_field_info* fields_info;
};

void
___sentient_model_info_store_model_info(
    struct sentient_model_info* model_info,
    ___sentient_type_id type_id);

const
struct sentient_model_info*
___sentient_model_info_get_model_info(
    ___sentient_type_id type_id);













#ifdef __cplusplus
}
#endif

#endif