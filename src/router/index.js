import { createRouter, createWebHistory } from 'vue-router'
import HomePage from '../views/HomePage.vue'
import EventDetail from '../views/EventDetail.vue'
import TeamPage from '../views/TeamPage.vue'

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
  },
  {
    path: '/team',
    name: 'team',
    component: TeamPage
  }
]

const router = createRouter({
  history: createWebHistory(),
  routes
})

export default router
