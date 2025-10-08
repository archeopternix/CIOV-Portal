import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'

// https://vite.dev/config/
export default defineConfig({
  plugins: [vue()],
  server: {
    host: true,
    port: 5000,
    allowedHosts: ['800a4827-a701-4676-bfde-dddeb51b6eed-00-3g2ndn66l3lvm.kirk.replit.dev'],
  },
})
