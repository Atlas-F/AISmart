# AISmart 说明文档

***

# LVGL嵌入式智能助手项目文档

## 项目概述

本项目是一个基于LVGL图形库的嵌入式智能助手系统，运行在Linux帧缓冲设备上。系统集成了DeepSeek AI接口，提供自然语言交互功能，并包含多个交互界面，包括主界面、AI聊天界面、功能菜单等。

项目核心特点：

- 使用LVGL v8.3.11构建现代化用户界面
- 集成DeepSeek AI API实现智能对话
- 支持触摸屏和手势操作
- 多屏幕切换与动画效果
- 实时时间显示和动态表情系统

## 项目结构

### 核心目录结构

```
AiSmart/
├── CMakeLists.txt          # 项目构建配置
	
├── main.c                 # 程序入口
├── depskmainCopy.c        # DeepSeek API接口实现
├── depskmainCopy.h        # DeepSeek API头文件
├── ui.c                   # UI主文件
├── ui.h                   # UI头文件
├── ui_events.c            # UI事件处理
├── ui_events.h            # UI事件头文件
├── ui_Screen1.c           # 主屏幕实现
├── ...                    # 其他屏幕实现文件
└── assets/                # 图片资源
```

### 关键文件说明

| 文件              | 功能描述                                              |
| :---------------- | :---------------------------------------------------- |
| `depskmainCopy.c` | DeepSeek API通信核心实现，包含会话管理、API调用等功能 |
| `ui.c`            | UI主逻辑，包含屏幕初始化、动画定义等                  |
| `ui_events.c`     | 事件处理逻辑，包括定时器、手势识别等                  |
| `ui_Screen1.c`    | 主屏幕实现，包含动态表情系统                          |

## 系统架构



<svg role="graphics-document document" viewBox="0 0 591.0250244140625 694" class="flowchart mermaid-svg" xmlns="http://www.w3.org/2000/svg" width="100%" id="mermaid-svg-19" style="max-width: 591.025px; transform-origin: 0px 0px; user-select: none; transform: translate(113.75px, 0px) scale(0.638383);"><g><marker orient="auto" markerHeight="8" markerWidth="8" markerUnits="userSpaceOnUse" refY="5" refX="5" viewBox="0 0 10 10" class="marker flowchart-v2" id="mermaid-svg-19_flowchart-v2-pointEnd"><path style="stroke-width: 1; stroke-dasharray: 1, 0;" class="arrowMarkerPath" d="M 0 0 L 10 5 L 0 10 z"></path></marker><marker orient="auto" markerHeight="8" markerWidth="8" markerUnits="userSpaceOnUse" refY="5" refX="4.5" viewBox="0 0 10 10" class="marker flowchart-v2" id="mermaid-svg-19_flowchart-v2-pointStart"><path style="stroke-width: 1; stroke-dasharray: 1, 0;" class="arrowMarkerPath" d="M 0 5 L 10 10 L 10 0 z"></path></marker><marker orient="auto" markerHeight="11" markerWidth="11" markerUnits="userSpaceOnUse" refY="5" refX="11" viewBox="0 0 10 10" class="marker flowchart-v2" id="mermaid-svg-19_flowchart-v2-circleEnd"><circle style="stroke-width: 1; stroke-dasharray: 1, 0;" class="arrowMarkerPath" r="5" cy="5" cx="5"></circle></marker><marker orient="auto" markerHeight="11" markerWidth="11" markerUnits="userSpaceOnUse" refY="5" refX="-1" viewBox="0 0 10 10" class="marker flowchart-v2" id="mermaid-svg-19_flowchart-v2-circleStart"><circle style="stroke-width: 1; stroke-dasharray: 1, 0;" class="arrowMarkerPath" r="5" cy="5" cx="5"></circle></marker><marker orient="auto" markerHeight="11" markerWidth="11" markerUnits="userSpaceOnUse" refY="5.2" refX="12" viewBox="0 0 11 11" class="marker cross flowchart-v2" id="mermaid-svg-19_flowchart-v2-crossEnd"><path style="stroke-width: 2; stroke-dasharray: 1, 0;" class="arrowMarkerPath" d="M 1,1 l 9,9 M 10,1 l -9,9"></path></marker><marker orient="auto" markerHeight="11" markerWidth="11" markerUnits="userSpaceOnUse" refY="5.2" refX="-1" viewBox="0 0 11 11" class="marker cross flowchart-v2" id="mermaid-svg-19_flowchart-v2-crossStart"><path style="stroke-width: 2; stroke-dasharray: 1, 0;" class="arrowMarkerPath" d="M 1,1 l 9,9 M 10,1 l -9,9"></path></marker><g class="root"><g class="clusters"></g><g class="edgePaths"><path marker-end="url(#mermaid-svg-19_flowchart-v2-pointEnd)" style="" class="edge-thickness-normal edge-pattern-solid edge-thickness-normal edge-pattern-solid flowchart-link" id="L_A_B_0" d="M308.075,62L308.075,66.167C308.075,70.333,308.075,78.667,308.075,86.333C308.075,94,308.075,101,308.075,104.5L308.075,108"></path><path marker-end="url(#mermaid-svg-19_flowchart-v2-pointEnd)" style="" class="edge-thickness-normal edge-pattern-solid edge-thickness-normal edge-pattern-solid flowchart-link" id="L_B_C_0" d="M308.075,166L308.075,170.167C308.075,174.333,308.075,182.667,308.075,190.333C308.075,198,308.075,205,308.075,208.5L308.075,212"></path><path marker-end="url(#mermaid-svg-19_flowchart-v2-pointEnd)" style="" class="edge-thickness-normal edge-pattern-solid edge-thickness-normal edge-pattern-solid flowchart-link" id="L_C_D_0" d="M308.075,270L308.075,274.167C308.075,278.333,308.075,286.667,308.075,294.333C308.075,302,308.075,309,308.075,312.5L308.075,316"></path><path marker-end="url(#mermaid-svg-19_flowchart-v2-pointEnd)" style="" class="edge-thickness-normal edge-pattern-solid edge-thickness-normal edge-pattern-solid flowchart-link" id="L_D_E_0" d="M246.075,361.518L219.396,367.765C192.717,374.012,139.358,386.506,112.679,396.253C86,406,86,413,86,416.5L86,420"></path><path marker-end="url(#mermaid-svg-19_flowchart-v2-pointEnd)" style="" class="edge-thickness-normal edge-pattern-solid edge-thickness-normal edge-pattern-solid flowchart-link" id="L_D_F_0" d="M308.075,374L308.075,378.167C308.075,382.333,308.075,390.667,308.075,398.333C308.075,406,308.075,413,308.075,416.5L308.075,420"></path><path marker-end="url(#mermaid-svg-19_flowchart-v2-pointEnd)" style="" class="edge-thickness-normal edge-pattern-solid edge-thickness-normal edge-pattern-solid flowchart-link" id="L_D_G_0" d="M370.075,363.37L392.567,369.308C415.058,375.246,460.042,387.123,482.533,396.562C505.025,406,505.025,413,505.025,416.5L505.025,420"></path><path marker-end="url(#mermaid-svg-19_flowchart-v2-pointEnd)" style="" class="edge-thickness-normal edge-pattern-solid edge-thickness-normal edge-pattern-solid flowchart-link" id="L_E_H_0" d="M86,478L86,482.167C86,486.333,86,494.667,86,502.333C86,510,86,517,86,520.5L86,524"></path><path marker-end="url(#mermaid-svg-19_flowchart-v2-pointEnd)" style="" class="edge-thickness-normal edge-pattern-solid edge-thickness-normal edge-pattern-solid flowchart-link" id="L_F_I_0" d="M308.075,478L308.075,482.167C308.075,486.333,308.075,494.667,308.075,502.333C308.075,510,308.075,517,308.075,520.5L308.075,524"></path><path marker-end="url(#mermaid-svg-19_flowchart-v2-pointEnd)" style="" class="edge-thickness-normal edge-pattern-solid edge-thickness-normal edge-pattern-solid flowchart-link" id="L_I_J_0" d="M262.342,582L255.285,586.167C248.227,590.333,234.112,598.667,227.054,606.333C219.997,614,219.997,621,219.997,624.5L219.997,628"></path><path marker-end="url(#mermaid-svg-19_flowchart-v2-pointEnd)" style="" class="edge-thickness-normal edge-pattern-solid edge-thickness-normal edge-pattern-solid flowchart-link" id="L_I_K_0" d="M353.808,582L360.865,586.167C367.923,590.333,382.038,598.667,389.096,606.333C396.153,614,396.153,621,396.153,624.5L396.153,628"></path></g><g class="edgeLabels"><g class="edgeLabel"><g transform="translate(0, 0)" class="label"><foreignObject height="0" width="0"><div class="labelBkg" xmlns="http://www.w3.org/1999/xhtml" style="background-color: rgba(232, 232, 232, 0.5); display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="edgeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51); background-color: rgba(232, 232, 232, 0.8); text-align: center;"></span></div></foreignObject></g></g><g class="edgeLabel"><g transform="translate(0, 0)" class="label"><foreignObject height="0" width="0"><div class="labelBkg" xmlns="http://www.w3.org/1999/xhtml" style="background-color: rgba(232, 232, 232, 0.5); display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="edgeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51); background-color: rgba(232, 232, 232, 0.8); text-align: center;"></span></div></foreignObject></g></g><g class="edgeLabel"><g transform="translate(0, 0)" class="label"><foreignObject height="0" width="0"><div class="labelBkg" xmlns="http://www.w3.org/1999/xhtml" style="background-color: rgba(232, 232, 232, 0.5); display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="edgeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51); background-color: rgba(232, 232, 232, 0.8); text-align: center;"></span></div></foreignObject></g></g><g class="edgeLabel"><g transform="translate(0, 0)" class="label"><foreignObject height="0" width="0"><div class="labelBkg" xmlns="http://www.w3.org/1999/xhtml" style="background-color: rgba(232, 232, 232, 0.5); display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="edgeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51); background-color: rgba(232, 232, 232, 0.8); text-align: center;"></span></div></foreignObject></g></g><g class="edgeLabel"><g transform="translate(0, 0)" class="label"><foreignObject height="0" width="0"><div class="labelBkg" xmlns="http://www.w3.org/1999/xhtml" style="background-color: rgba(232, 232, 232, 0.5); display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="edgeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51); background-color: rgba(232, 232, 232, 0.8); text-align: center;"></span></div></foreignObject></g></g><g class="edgeLabel"><g transform="translate(0, 0)" class="label"><foreignObject height="0" width="0"><div class="labelBkg" xmlns="http://www.w3.org/1999/xhtml" style="background-color: rgba(232, 232, 232, 0.5); display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="edgeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51); background-color: rgba(232, 232, 232, 0.8); text-align: center;"></span></div></foreignObject></g></g><g class="edgeLabel"><g transform="translate(0, 0)" class="label"><foreignObject height="0" width="0"><div class="labelBkg" xmlns="http://www.w3.org/1999/xhtml" style="background-color: rgba(232, 232, 232, 0.5); display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="edgeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51); background-color: rgba(232, 232, 232, 0.8); text-align: center;"></span></div></foreignObject></g></g><g class="edgeLabel"><g transform="translate(0, 0)" class="label"><foreignObject height="0" width="0"><div class="labelBkg" xmlns="http://www.w3.org/1999/xhtml" style="background-color: rgba(232, 232, 232, 0.5); display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="edgeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51); background-color: rgba(232, 232, 232, 0.8); text-align: center;"></span></div></foreignObject></g></g><g class="edgeLabel"><g transform="translate(0, 0)" class="label"><foreignObject height="0" width="0"><div class="labelBkg" xmlns="http://www.w3.org/1999/xhtml" style="background-color: rgba(232, 232, 232, 0.5); display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="edgeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51); background-color: rgba(232, 232, 232, 0.8); text-align: center;"></span></div></foreignObject></g></g><g class="edgeLabel"><g transform="translate(0, 0)" class="label"><foreignObject height="0" width="0"><div class="labelBkg" xmlns="http://www.w3.org/1999/xhtml" style="background-color: rgba(232, 232, 232, 0.5); display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="edgeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51); background-color: rgba(232, 232, 232, 0.8); text-align: center;"></span></div></foreignObject></g></g></g><g class="nodes"><g transform="translate(308.0750045776367, 35)" id="flowchart-A-0" class="node default"><rect height="54" width="161.6125030517578" y="-27" x="-80.8062515258789" style="" class="basic label-container"></rect><g transform="translate(-50.806251525878906, -12)" style="" class="label"><rect></rect><foreignObject height="24" width="101.61250305175781"><div xmlns="http://www.w3.org/1999/xhtml" style="display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="nodeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51);"><p style="margin: 0px;">主程序 main.c</p></span></div></foreignObject></g></g><g transform="translate(308.0750045776367, 139)" id="flowchart-B-1" class="node default"><rect height="54" width="142.2125015258789" y="-27" x="-71.10625076293945" style="" class="basic label-container"></rect><g transform="translate(-41.10625076293945, -12)" style="" class="label"><rect></rect><foreignObject height="24" width="82.2125015258789"><div xmlns="http://www.w3.org/1999/xhtml" style="display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="nodeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51);"><p style="margin: 0px;">LVGL初始化</p></span></div></foreignObject></g></g><g transform="translate(308.0750045776367, 243)" id="flowchart-C-3" class="node default"><rect height="54" width="154.8375015258789" y="-27" x="-77.41875076293945" style="" class="basic label-container"></rect><g transform="translate(-47.41875076293945, -12)" style="" class="label"><rect></rect><foreignObject height="24" width="94.8375015258789"><div xmlns="http://www.w3.org/1999/xhtml" style="display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="nodeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51);"><p style="margin: 0px;">UI系统初始化</p></span></div></foreignObject></g></g><g transform="translate(308.0750045776367, 347)" id="flowchart-D-5" class="node default"><rect height="54" width="124" y="-27" x="-62" style="" class="basic label-container"></rect><g transform="translate(-32, -12)" style="" class="label"><rect></rect><foreignObject height="24" width="64"><div xmlns="http://www.w3.org/1999/xhtml" style="display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="nodeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51);"><p style="margin: 0px;">屏幕管理</p></span></div></foreignObject></g></g><g transform="translate(86, 451)" id="flowchart-E-7" class="node default"><rect height="54" width="108" y="-27" x="-54" style="" class="basic label-container"></rect><g transform="translate(-24, -12)" style="" class="label"><rect></rect><foreignObject height="24" width="48"><div xmlns="http://www.w3.org/1999/xhtml" style="display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="nodeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51);"><p style="margin: 0px;">主屏幕</p></span></div></foreignObject></g></g><g transform="translate(308.0750045776367, 451)" id="flowchart-F-9" class="node default"><rect height="54" width="137.9000015258789" y="-27" x="-68.95000076293945" style="" class="basic label-container"></rect><g transform="translate(-38.95000076293945, -12)" style="" class="label"><rect></rect><foreignObject height="24" width="77.9000015258789"><div xmlns="http://www.w3.org/1999/xhtml" style="display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="nodeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51);"><p style="margin: 0px;">AI聊天屏幕</p></span></div></foreignObject></g></g><g transform="translate(505.0250015258789, 451)" id="flowchart-G-11" class="node default"><rect height="54" width="156" y="-27" x="-78" style="" class="basic label-container"></rect><g transform="translate(-48, -12)" style="" class="label"><rect></rect><foreignObject height="24" width="96"><div xmlns="http://www.w3.org/1999/xhtml" style="display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="nodeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51);"><p style="margin: 0px;">功能菜单屏幕</p></span></div></foreignObject></g></g><g transform="translate(86, 555)" id="flowchart-H-13" class="node default"><rect height="54" width="156" y="-27" x="-78" style="" class="basic label-container"></rect><g transform="translate(-48, -12)" style="" class="label"><rect></rect><foreignObject height="24" width="96"><div xmlns="http://www.w3.org/1999/xhtml" style="display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="nodeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51);"><p style="margin: 0px;">动态表情系统</p></span></div></foreignObject></g></g><g transform="translate(308.0750045776367, 555)" id="flowchart-I-15" class="node default"><rect height="54" width="188.15000915527344" y="-27" x="-94.07500457763672" style="" class="basic label-container"></rect><g transform="translate(-64.07500457763672, -12)" style="" class="label"><rect></rect><foreignObject height="24" width="128.15000915527344"><div xmlns="http://www.w3.org/1999/xhtml" style="display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="nodeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51);"><p style="margin: 0px;">DeepSeek API集成</p></span></div></foreignObject></g></g><g transform="translate(219.99687957763672, 659)" id="flowchart-J-17" class="node default"><rect height="54" width="124" y="-27" x="-62" style="" class="basic label-container"></rect><g transform="translate(-32, -12)" style="" class="label"><rect></rect><foreignObject height="24" width="64"><div xmlns="http://www.w3.org/1999/xhtml" style="display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="nodeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51);"><p style="margin: 0px;">网络通信</p></span></div></foreignObject></g></g><g transform="translate(396.1531295776367, 659)" id="flowchart-K-19" class="node default"><rect height="54" width="128.3125" y="-27" x="-64.15625" style="" class="basic label-container"></rect><g transform="translate(-34.15625, -12)" style="" class="label"><rect></rect><foreignObject height="24" width="68.3125"><div xmlns="http://www.w3.org/1999/xhtml" style="display: table-cell; white-space: nowrap; line-height: 1.5; max-width: 200px; text-align: center;"><span class="nodeLabel" style="fill: rgb(51, 51, 51); color: rgb(51, 51, 51);"><p style="margin: 0px;">JSON解析</p></span></div></foreignObject></g></g></g></g></g></svg>

## 功能模块

### 1. DeepSeek API集成

- **会话管理**：创建、销毁会话，维护API密钥
- **消息发送**：处理用户输入并发送到DeepSeek API
- **响应解析**：解析JSON响应并提取内容
- **令牌统计**：跟踪API使用情况和成本估算

### 2. 用户界面系统

- **多屏幕管理**：5个主要交互屏幕
- **动态表情**：随机切换的动画表情系统
- **时间显示**：实时时钟和日期
- **手势支持**：左右滑动切换屏幕

### 3. 输入系统

- **虚拟键盘**：集成LVGL键盘组件
- **文本区域**：支持多行文本输入
- **麦克风按钮**：语音输入支持（待实现）

## 构建与运行

### 依赖项

- LVGL v8.3.11
- cURL库（带SSL支持）
- cJSON库
- Linux帧缓冲设备

### 交叉编译步骤



```

```

### 目标设备部署



```
# 将可执行文件和资源文件复制到设备
scp lvgl_fb user@device:/app/
scp -r assets user@device:/app/

# 设置环境变量（可选）
export DEEPSEEK_API_KEY=your_api_key
```

## 使用指南

### 主界面操作

1. **长按中心区域**：激活AI聊天功能
2. **左右滑动**：切换到其他功能屏幕
3. **时间区域**：常态界面下滑显示时间日期

### AI聊天界面

1. **长按输入图标**：调出键盘和输入框
2. **输入问题**：在文本区域输入问题
3. **点击提交**：发送问题并获取AI回复
4. **回复显示**：AI回复显示在顶部面板

### 手势控制

| 手势 | 功能             |
| :--- | :--------------- |
| 左滑 | 切换到下一个屏幕 |
| 右滑 | 切换到上一个屏幕 |
| 下滑 | 显示快捷菜单     |

## API接口说明

### DeepSeek会话管理



```
// 创建会话
DeepSeekSession* session = deepseek_create_session("your_api_key");

// 发送消息
char* response = deepseek_send_message(session, "Hello", 
                                      &prompt_tokens, 
                                      &completion_tokens, 
                                      &total_tokens);

// 销毁会话
deepseek_destroy_session(session);
```

### UI事件处理



```
// 输入事件处理
void ui_event_inputlogo(lv_event_t * e) {
    if(event_code == LV_EVENT_LONG_PRESSED) {
        // 显示键盘和输入框
        lv_obj_clear_flag(ui_TextArea1, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN);
    }
    
    if(event_code == LV_EVENT_CLICKED) {
        // 提交问题
        get_full_text_input(input, sizeof(input));
        char* response = deepseek_send_message(session, input, ...);
        lv_label_set_text(ui_AILabel, response);
    }
}
```

## 关键功能实现

### 动态表情系统



```
// 定时器回调函数
static void emoji_change_timer_cb(lv_timer_t *timer) {
    lv_obj_t *container = /* 获取表情容器 */;
    uint16_t child_cnt = lv_obj_get_child_cnt(container);
    
    // 生成随机索引
    uint16_t idx = rand() % child_cnt;
    
    // 隐藏上一个表情
    lv_obj_add_flag(lv_obj_get_child(container, last_idx), LV_OBJ_FLAG_HIDDEN);
    
    // 显示新表情
    lv_obj_clear_flag(lv_obj_get_child(container, idx), LV_OBJ_FLAG_HIDDEN);
    
    // 更新索引
    last_idx = idx;
}
```

### 文本输入处理



```
void get_full_text_input(char *dest, size_t dest_size) {
    const char *text = lv_textarea_get_text(ui_TextArea1);
    size_t text_len = strlen(text);
    
    // 安全复制文本
    size_t copy_len = text_len < dest_size - 1 ? text_len : dest_size - 1;
    strncpy(dest, text, copy_len);
    dest[copy_len] = '\0';
    
    // 移除换行符
    char *newline = strchr(dest, '\n');
    if(newline) *newline = '\0';
}
```

## 故障排除

### 常见问题及解决方案

1. **API连接失败**
   - 检查网络连接
   - 验证API密钥有效性
   - 确保设备时间正确
2. **UI元素不显示**
   - 检查资源文件路径
   - 确认屏幕分辨率设置
   - 验证LVGL初始化流程
3. **输入文本截断**
   - 使用`get_full_text_input`而非`sscanf`
   - 增加输入缓冲区大小
4. **内存不足**
   - 启用编译优化：`set(CMAKE_C_FLAGS "-Os")`
   - 减少同时显示的UI元素

## 性能优化建议

1. **资源优化**
   - 使用LVGL的图片转换工具优化资源
   - 减少大尺寸图片使用
   - 启用LVGL的缓存机制
2. **内存管理**
   - 及时释放API响应内存
   - 使用静态分配代替动态分配
   - 监控内存使用情况
3. **网络优化**
   - 减少API调用频率
   - 使用HTTP长连接
   - 压缩请求数据

## 扩展与定制

### 添加新功能

1. 在`ui_events.c`中实现新的事件处理函数
2. 在SquareLine Studio中设计新界面
3. 将新界面集成到现有屏幕管理系统

### 修改AI行为

1. 编辑`depskmainCopy.c`中的API参数
   - 修改模型：`cJSON_AddStringToObject(root, "model", "your-model")`
   - 调整令牌限制：`cJSON_AddNumberToObject(root, "max_tokens", 1024)`



## 贡献指南

欢迎通过GitHub提交贡献：

1. Fork项目仓库
2. 创建特性分支：`git checkout -b feature/new-feature`
3. 提交更改：`git commit -m 'Add new feature'`
4. 推送到分支：`git push origin feature/new-feature`
5. 创建Pull Request

### 代码规范

- 遵循LVGL命名约定
- 所有公共函数必须有Doxygen注释
- 保持一致的缩进（4个空格）
- 添加新功能时提供单元测试

## 许可证

本项目采用 **MIT许可证** - 详见项目根目录下的LICENSE文件。

------

> **最后更新**：2025年6月18日
> **技术支持**：[lfg@example.com](https://mailto:lfg@example.com/)
> **项目仓库**：https://github.com/yourusername/lvgl_fb