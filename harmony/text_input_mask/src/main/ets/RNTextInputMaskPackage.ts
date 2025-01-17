/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

import { RNPackage, TurboModulesFactory } from '@rnoh/react-native-openharmony/ts';
import type { TurboModule, TurboModuleContext } from '@rnoh/react-native-openharmony/ts';
import { RNTextInputMaskTurboModule } from './RNTextInputMaskTurboModle';

class RNTextInputMaskTurboModuleFactory extends TurboModulesFactory {
  createTurboModule(name: string): TurboModule | null {
    globalThis.uiAbilityContext = this.ctx.uiAbilityContext
    if (this.hasTurboModule(name)) {
      return new RNTextInputMaskTurboModule(this.ctx);
    }
    return null;
  }

  hasTurboModule(name: string): boolean {
    return name === "RNTextInputMask";
  }
}

export class RNTextInputMaskPackage extends RNPackage {
  createTurboModulesFactory(ctx: TurboModuleContext): TurboModulesFactory {
    return new RNTextInputMaskTurboModuleFactory(ctx);
  }
}