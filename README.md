# 🚗 VehicleSystem

`VehicleSystem` 是一个基于 **C++** 和 **Qt/QML** 开发的模块化车载系统项目，适用于车机界面模拟、车载多媒体、信息显示等场景。该项目采用 **CMake** 构建，结构清晰，适合学习、演示和二次开发。

---

## 📁 项目结构

```plaintext
VehicleSystem/
├── src/                # 源代码目录（包含主程序和模块）
├── CMakeLists.txt      # 顶层 CMake 构建脚本
├── .dockerignore       # Docker 忽略文件
├── .gitignore          # Git 忽略文件
└── README.md           # 项目说明文档（你现在看到的这个）
````


## 🧱 构建与运行

### ✅ 环境要求

* Qt 6.2+（推荐使用 Qt 6 + QML）
* C++17 编译器（如 g++、MSVC）
* CMake 3.14 及以上版本
* 可选工具：

  * VS Code 或 Qt Creator
  * Docker（用于封装环境，开发中）

### 🧪 构建步骤（本地）

```bash
# 克隆仓库
git clone https://github.com/Seven-second-fish/VehicleSystem.git
cd VehicleSystem

# 创建构建目录
mkdir build && cd build

# 配置构建
cmake ..

# 编译
cmake --build .

# 运行
./VehicleSystem
```

---

## ✨ 功能规划

* [x] 启动页面展示
* [x] 多媒体模块（音频/视频播放）
* [ ] 仪表盘 UI 模拟（速度表、转速表）
* [ ] 系统设置模块（亮度、语言、主题等）
* [ ] 模块化架构（基于 CMake + Qt QML）
* [ ] Docker 镜像一键启动（开发中）

---

## 🧰 技术栈

* Qt 6 + QML 前端界面
* C++17 后端逻辑处理
* CMake 构建系统
* Docker（可选：开发/部署容器环境）
* VS Code / Qt Creator IDE

---

## 🗂️ 模块化说明（计划）

项目计划将每个功能封装为独立模块，例如：

* `StartPageModule`
* `MediaModule`
* `DashboardModule`
* `SettingsModule`

每个模块将拥有独立的 QML 文件、C++ 类和构建定义，使用 `qt_add_qml_module()` 管理。

---

## 🤝 贡献指南

欢迎感兴趣的开发者参与项目！你可以通过以下方式贡献：

* 提交 Issue 或建议
* Fork 项目并发起 Pull Request
* 修复 Bug、优化 UI 或扩展功能

---

## 📄 License

本项目当前未添加开源协议，仅供学习和交流使用，请勿直接用于商业用途。如需合作或授权请联系作者。

---

## 📬 联系方式

* 作者：Seven-second-fish
* GitHub：[https://github.com/Seven-second-fish](https://github.com/Seven-second-fish)

---

```

这个版本已经完全符合 `.md` 格式规范，排版清晰，可以直接用在 GitHub 上显示成美观的说明页面。

需要我帮你自动生成模块模板或写个 Docker 启动脚本也可以说一声。你打算接下来做哪个模块？我可以帮你整理结构。
```
