/*
 * Copyright (c) 2019-2022 Rockchip Eletronics Co., Ltd.
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
 */
#ifndef _RK_AIQ_DPCC_HANDLE_INT_H_
#define _RK_AIQ_DPCC_HANDLE_INT_H_

#include "RkAiqHandle.h"
#include "adpcc/rk_aiq_uapi_adpcc_int.h"
#include "rk_aiq_api_private.h"
#include "rk_aiq_pool.h"
#include "xcam_mutex.h"

namespace RkCam {

class RkAiqAdpccHandleInt : virtual public RkAiqHandle {
 public:
    explicit RkAiqAdpccHandleInt(RkAiqAlgoDesComm* des, RkAiqCore* aiqCore)
        : RkAiqHandle(des, aiqCore) {
#ifndef DISABLE_HANDLE_ATTRIB
        memset(&mCurAtt, 0, sizeof(rk_aiq_dpcc_attrib_V20_t));
        memset(&mNewAtt, 0, sizeof(rk_aiq_dpcc_attrib_V20_t));
#endif
    };
    virtual ~RkAiqAdpccHandleInt() { RkAiqHandle::deInit(); };
    virtual XCamReturn updateConfig(bool needSync);
    virtual XCamReturn prepare();
    virtual XCamReturn preProcess();
    virtual XCamReturn processing();
    virtual XCamReturn postProcess();
    virtual XCamReturn genIspResult(RkAiqFullParams* params, RkAiqFullParams* cur_params);
    // TODO add algo specific methords, this is a sample
    XCamReturn setAttrib(rk_aiq_dpcc_attrib_V20_t* att);
    XCamReturn getAttrib(rk_aiq_dpcc_attrib_V20_t* att);

 protected:
    virtual void init();
    virtual void deInit() { RkAiqHandle::deInit(); };

 private:
    // TODO
#ifndef DISABLE_HANDLE_ATTRIB
    rk_aiq_dpcc_attrib_V20_t mCurAtt;
    rk_aiq_dpcc_attrib_V20_t mNewAtt;
#endif

 private:
    DECLARE_HANDLE_REGISTER_TYPE(RkAiqAdpccHandleInt);
};

}  // namespace RkCam

#endif
