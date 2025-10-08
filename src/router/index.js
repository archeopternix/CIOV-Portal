import { createRouter, createWebHistory } from 'vue-router'
import HomePage from '../views/HomePage.vue'
import EventDetail from '../views/EventDetail.vue'

const routes = [
  {
    path: '/',
    name: 'home',
    component: HomePage
  },
  {
    path: '/event/:id',
    name: 'event-detail',
    component: EventDetail
  }
]

const router = createRouter({
  history: createWebHistory(),
  routes
})

export default router
