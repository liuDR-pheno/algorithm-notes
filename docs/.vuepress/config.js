import { defaultTheme } from '@vuepress/theme-default'
import { defineUserConfig } from 'vuepress'
import { viteBundler } from '@vuepress/bundler-vite'

export default defineUserConfig({
  lang: 'zh-CN',
  title: '算法刷题笔记',
  description: '个人算法刷题记录，包含思路笔记和题解代码',

  theme: defaultTheme({
    sidebarDepth: 2,
    navbar: [
      '/',
      {
        text: '算法笔记',
        link: '/algorithm/',
      },
    ],

    sidebar: {
      '/algorithm/': [
        {
          text: '算法刷题',
          children: [
            '/algorithm/README.md',
            '/algorithm/链表.md',
            '/algorithm/数组.md',
            '/algorithm/双指针.md',
            '/algorithm/字符串.md',
            '/algorithm/树与图.md',
            '/algorithm/动态规划.md',
            '/algorithm/手写题.md',
            '/algorithm/其他.md',
          ],
        },
      ],
    },
  }),

  bundler: viteBundler(),
})
