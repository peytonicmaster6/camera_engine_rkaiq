/*
 *rk_aiq_types_alsc_algo_prvt.h
 *
 *  Copyright (c) 2019 Rockchip Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef _RK_AIQ_TYPES_AYNR_ALGO_PRVT_V3_H_
#define _RK_AIQ_TYPES_AYNR_ALGO_PRVT_V3_H_

#include "aynr3/rk_aiq_types_aynr_algo_int_v3.h"
#include "RkAiqCalibDbTypes.h"
#include "xcam_log.h"
#include "xcam_common.h"

//RKAIQ_BEGIN_DECLARE



//anr context
typedef struct Aynr_Context_V3_s {
    Aynr_ExpInfo_V3_t stExpInfo;
    Aynr_State_V3_t eState;
    Aynr_OPMode_V3_t eMode;

    Aynr_Auto_Attr_V3_t stAuto;
    Aynr_Manual_Attr_V3_t stManual;
    //struct list_head* list_ynr_v3;

    rk_aiq_ynr_strength_v3_t stStrength;

    bool isIQParaUpdate;
    bool isGrayMode;
    Aynr_ParamMode_V3_t eParamMode;

    int rawWidth;
    int rawHeight;
    int prepare_type;

    CalibDbV2_YnrV3_t ynr_v3;
    int isReCalculate;
} Aynr_Context_V3_t;






//RKAIQ_END_DECLARE

#endif


