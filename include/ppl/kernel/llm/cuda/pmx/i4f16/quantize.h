// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef __PPL_KERNEL_LLM_CUDA_PMX_I4F16_QUANTIZE_H__
#define __PPL_KERNEL_LLM_CUDA_PMX_I4F16_QUANTIZE_H__

#include "ppl/kernel/llm/cuda/common/general_include.h"

#include <cuda_fp16.h>

namespace ppl { namespace kernel { namespace llm { namespace cuda { namespace pmx { namespace i4f16 {

ppl::common::RetCode minmax_quantize_fp16(
    cudaStream_t stream,
    const void* input, // [N, K], fp16
    const int64_t N,
    const int64_t K, // must aligned 128 now
    const int64_t group_size,
    void* quantized, // [N/4, K], int4x4
    void* scale  // [K/group_size, N], fp16
);

ppl::common::RetCode minmax_dequantize_fp16(
    cudaStream_t stream,
    const void* input, // [N/4, K], int4x4
    const void* scale, // [K/group_size, N], fp16
    const int64_t N,
    const int64_t K, // must aligned 128 now
    const int64_t group_size,
    void* output // [N, K], fp16
);

}}}}}}

#endif
