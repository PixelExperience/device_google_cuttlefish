//
// Copyright (C) 2022 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>

#include "common/libs/utils/result.h"
#include "host/libs/web/http_client/http_client.h"

namespace cuttlefish {

struct GCPInstance {
  int disk_size_gb;
  const char* machine_type;
  const char* min_cpu_platform;
};

struct CreateHostInstanceRequest {
  GCPInstance* gcp;
};

class CloudOrchestratorApi {
 public:
  CloudOrchestratorApi(const std::string& service_url, const std::string& zone,
                       HttpClient& http_client);
  ~CloudOrchestratorApi();

  Result<std::string> CreateHost(const CreateHostInstanceRequest& request);

  Result<std::vector<std::string>> ListHosts();

  Result<std::vector<std::string>> ListCVDWebRTCStreams(
      const std::string& host);

 private:
  const std::string& service_url_;
  const std::string& zone_;
  HttpClient& http_client_;
};

}  // namespace cuttlefish
