# 算法刷题笔记

个人算法刷题记录，使用 VuePress 搭建的文档站点。

## 技术栈

- **文档框架**: VuePress 2
- **包管理器**: pnpm
- **Node.js**: >= 14.0.0

## 快速开始

```bash
# 安装依赖
pnpm install

# 启动开发服务器
pnpm docs:dev

# 构建静态站点
pnpm docs:build
```

## 项目结构

```
algorithm-notes/
├── docs/              # VuePress 文档
│   ├── .vuepress/     # VuePress 配置
│   └── algorithm/     # 算法笔记 Markdown
├── code/              # 题解代码（.js 文件）
├── package.json
└── README.md
```

## 使用说明

- **算法笔记**：在 `docs/algorithm/` 下用 Markdown 记录每道题的思路和心得
- **题解代码**：在 `code/` 目录下存放 JavaScript 题解文件
