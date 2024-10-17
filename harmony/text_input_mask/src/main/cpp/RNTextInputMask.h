
/**
 * This code was generated by "react-native codegen-harmony"
 *
 * Do not edit this file as changes may cause incorrect behavior and will be
 * lost once the code is regenerated.
 *
 * @generatorVersion: 1
 */
#pragma once

#include "RNOH/ArkTSTurboModule.h"
#include "RNOH/arkui/NativeNodeApi.h"
#include "RNOH/arkui/TextInputNode.h"
#include "common/model/Notation.h"
#include "common/RTLMask.h"
#include "common/model/AffinityCalculationStrategy.h"
using namespace rnoh;
using namespace facebook;
using namespace TinpMask;
namespace rnoh {
struct MaskParams {
    std::string mask;                 // mask的格式
    std::string value;                // 待mask的值
    std::optional<bool> autocomplete; // 布尔值，表示是否自动完成
    MaskParams() = default;
    MaskParams(const std::string &m, const std::string &v, std::optional<bool> autoComplete = std::nullopt)
        : mask(m), value(v), autocomplete(autoComplete) {} // 构造函数
    MaskParams &operator=(const MaskParams &input) {
        this->mask = input.mask;
        this->value = input.value;
        this->autocomplete = input.autocomplete;
        return *this;
    }
};

struct MaskOptions {
    std::optional<std::vector<std::string>> affineFormats;  // 可选的字符串数组
    std::optional<std::vector<Notation>> customNotations;   // 可选的 Notation 数组
    std::optional<std::string> affinityCalculationStrategy; // 可选字符串
    std::optional<bool> autocomplete;                       // 可选布尔值
    std::optional<bool> autoskip;                           // 可选布尔值
    std::optional<bool> rightToLeft;                        // 可选布尔值

    MaskOptions()
        : affineFormats(std::vector<std::string>()), customNotations(std::vector<Notation>()),
          affinityCalculationStrategy(std::nullopt), autocomplete(true), autoskip(false), rightToLeft(false) {}
    MaskOptions(const std::vector<std::string> &formats, const std::vector<Notation> &notations,
                const std::string &strategy, bool autoComp, bool autoSkip, bool rtl)
        : affineFormats(formats), customNotations(notations),
          affinityCalculationStrategy(strategy.empty() ? std::nullopt : std::make_optional(strategy)),
          autocomplete(autoComp), autoskip(autoSkip), rightToLeft(rtl) {}
};
typedef struct {
    ArkUI_NodeHandle data;
    MaskOptions maskOptions;
    std::string primaryFormat;
    int node;
    std::string lastInputText = "";
} UserData;

class JSI_EXPORT RNTextInputMask : public ArkTSTurboModule {
public:
    RNTextInputMask(const ArkTSTurboModule::Context ctx, const std::string name);
    // reactNode: number, primaryFormat: string, options: TM.RNTextInputMask.MaskOptions
    void setMask(int reactNode, std::string primaryFormat, MaskOptions options);
    jsi::Value mask(std::string mask, std::string value, bool autocomplete);
    jsi::Value unmask(std::string mask, std::string value, bool autocomplete);
    jsi::Runtime *grt = nullptr;
    std::shared_ptr<Mask> pickMask(const CaretString &text, MaskOptions maskOptions, std::string primaryMask);
    
//                 if (userData->maskOptions != nullptr) {
//                     delete userData->maskOptions;
//                     userData->maskOptions = nullptr;
//                 }

    // 释放资源
    ~RNTextInputMask() {
        for (auto userData : m_userDatas) {
            if (userData != nullptr) {
                delete userData;
                userData = nullptr;
            }
        }
    }


private:
    std::unordered_set<UserData *> m_userDatas;
};


} // namespace rnoh
