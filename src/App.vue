<script setup>
import { useRouter } from 'vue-router'

const router = useRouter()

const navigateTo = (path) => {
  router.push(path)
}
</script>

<template>
  <div class="app-container">
    <!-- Header Section -->
    <header class="header">
      <div class="logo" @click="navigateTo('/')">
        <img src="/logo.png" alt="Logo" />
      </div>
      <nav class="nav-menu">
        <a @click="navigateTo('/')">Events</a>
        <a @click="navigateTo('/team')">Team</a>
        <a href="#sponsors">Sponsors</a>
        <a href="#contact">Contact</a>
      </nav>
    </header>

    <!-- Router View -->
    <main class="main-content">
      <router-view />
    </main>
  </div>
</template>

<style scoped>
.app-container {
  width: 100%;
}

.header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 20px 40px;
  border-bottom: 1px solid #e0e0e0;
  max-width: 1400px;
  margin: 0 auto;
}

.logo {
  cursor: pointer;
}

.logo img {
  height: 60px;
  width: auto;
}

.nav-menu {
  display: flex;
  gap: 30px;
}

.nav-menu a {
  color: #333;
  text-decoration: none;
  font-size: 16px;
  font-weight: 500;
  transition: color 0.3s ease;
  cursor: pointer;
}

.nav-menu a:hover {
  color: #0066cc;
}

.main-content {
  max-width: 1400px;
  margin: 0 auto;
  padding: 20px;
}
</style>
