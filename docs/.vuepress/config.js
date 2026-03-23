import { defaultTheme } from '@vuepress/theme-default'
import { defineUserConfig } from 'vuepress'
import { viteBundler } from '@vuepress/bundler-vite'

export default defineUserConfig({
  lang: 'zh-CN',
  title: 'pheno个人博客',
  description: '个人博客，包含算法刷题记录，数据库笔记，个人项目等',

  theme: defaultTheme({
    sidebarDepth: 2,
    navbar: [
      '/',
      {
        text: '算法笔记',
        link: '/algorithm/',
      },
      {
        text: '数据库笔记',
        link: '/database/',
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
            '/algorithm/查找.md',
            '/algorithm/双指针.md',
            '/algorithm/字符串.md',
            '/algorithm/树与图.md',
            '/algorithm/动态规划.md',
            '/algorithm/其他.md',
          ],
        },
      ],
      '/database/': [
        {
          text: '数据库基础',
          children: [
            '/database/README.md',
            '/database/DataBase.md',
          ],
        },
      ],
    },
  }),

  bundler: viteBundler(),
})
