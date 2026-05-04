# Hardware-Aware-DSP-Agent
面向资源受限穿戴设备的软硬件协同设计与 DSP 算法自动化下发中枢

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Language](https://img.shields.io/badge/Language-Python%20%7C%20C99-success.svg)]()
[![Environment](https://img.shields.io/badge/Environment-Ubuntu%20%7C%20Makefile-orange.svg)]()
[![Status: PoC](https://img.shields.io/badge/Status-Proof%20of%20Concept-purple)]()

> A Hardware-Software Co-design Agent System for Resource-Constrained Wearable Devices.
> 面向资源受限穿戴设备的“软硬件协同设计”与 DSP 算法自动化下发中枢。

## 项目背景 

在面向高鲁棒性穿戴式生理信号提取时，研究人员通常利用Python等高级语言验证复杂的抗运动伪影算法。然而，将这些高阶浮点算法下放至真实的底层硬件架构时，面临着巨大的鸿沟：
1. 算力与内存约束：底层微控制器难以承担高并发的浮点运算，直接部署会导致严重的功耗透支与延迟。
2. 工程重构壁垒：手工将算法拆解为符合嵌入式规范的C语言多文件结构、配置交叉编译的Makefile，并在虚拟环境中处理各种指针溢出问题，极耗心智且易错。
本项目构建了一个多Agent协同系统，突破了纯算法生成的局限，引入了“硬件感知 (Hardware-Aware)” 能力。系统能够根据底层设备的物理约束，自动执行算法的定点化降维，并一键完成裸机代码的闭环构建与安全验证。

## 核心架构与逻辑流
本项目由三个高度专业化的 Agent 协同工作，形成长链推理闭环：
## 1. 量化智能体
核心逻辑：突破传统代码翻译，执行浮点到定点（Float-to-Fixed）的底层降维推理。
动作：根据目标硬件的字长（如 16-bit/32-bit），自动计算最优的Q-format比例因子，将高耗能的浮点乘除法重构为硬件友好的位移（Shift）与整数运算，兼顾系统性能与信号重构精度。

## 2. 重构智能体 
核心逻辑：遵循严格的嵌入式C言规范进行项目脚手架搭建。
动作：推导内存分配边界，将量化后的逻辑拆分为模块化的 ‘.c’和 ‘.h`’多文件结构，并基于硬件架构依赖自动生成包含优化指令的Makefile。

## 3. 沙箱验证智能体 (Sandbox Agent)
核心逻辑：硬件在环验证（Hardware-in-the-Loop Simulation）雏形。
动作：在Ubuntu虚拟环境沙箱中自动挂载生成的文件，执行‘make’编译指令。通过长链日志分析捕获潜在的指针越界、内存泄漏（Core Dump）问题，并将底层报错反推给重构 Agent 进行代码自愈。

## 快速开始 (Quick Start)

当前仓库提供核心协同逻辑的演示版本（PoC）。

## 环境依赖
bash
# 推荐在 Ubuntu 环境下运行，确保已安装 GCC 与 Make 工具链
sudo apt-get install gcc make
pip install -r requirements.txt
