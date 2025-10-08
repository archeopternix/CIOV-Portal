<script setup>
import { ref, onMounted } from 'vue'
import { useRouter } from 'vue-router'

const router = useRouter()
const events = ref([])
const currentSlide = ref(0)
const loading = ref(true)

onMounted(async () => {
  try {
    const eventFiles = ['cio-network-london-nov-2025']
    
    const loadedEvents = await Promise.all(
      eventFiles.map(async (file) => {
        try {
          const response = await fetch(`/events/${file}.md`)
          const markdown = await response.text()
          
          const frontmatterRegex = /^---\n([\s\S]*?)\n---\n([\s\S]*)$/
          const match = markdown.match(frontmatterRegex)
          
          if (match) {
            const frontmatter = match[1]
            const data = { id: file }
            frontmatter.split('\n').forEach(line => {
              const [key, ...valueParts] = line.split(':')
              if (key && valueParts.length) {
                data[key.trim()] = valueParts.join(':').trim()
              }
            })
            return data
          }
          return null
        } catch (error) {
          console.error(`Error loading event ${file}:`, error)
          return null
        }
      })
    )
    
    events.value = loadedEvents.filter(e => e !== null)
  } catch (error) {
    console.error('Error loading events:', error)
  } finally {
    loading.value = false
  }
})

const nextSlide = () => {
  currentSlide.value = (currentSlide.value + 1) % events.value.length
}

const prevSlide = () => {
  currentSlide.value = (currentSlide.value - 1 + events.value.length) % events.value.length
}

const goToSlide = (index) => {
  currentSlide.value = index
}

const viewEvent = (eventId) => {
  router.push(`/event/${eventId}`)
}
</script>

<template>
  <div class="homepage">
    <section class="hero-section">
      <h1>Upcoming Events</h1>
      <p class="subtitle">Join the UK's most influential IT Leaders</p>
    </section>

    <div v-if="!loading && events.length > 0" class="carousel-container">
      <div class="carousel">
        <button class="carousel-btn prev" @click="prevSlide" v-if="events.length > 1">‹</button>
        
        <div class="carousel-slides">
          <div 
            v-for="(event, index) in events" 
            :key="event.id"
            class="carousel-slide"
            :class="{ active: index === currentSlide }"
          >
            <div class="event-card">
              <div class="event-image" v-if="event.hotelImage">
                <img :src="event.hotelImage" :alt="event.location" />
              </div>
              <div class="event-content">
                <h2>{{ event.title }}</h2>
                <div class="event-info">
                  <p class="event-location">📍 {{ event.location }}</p>
                  <p class="event-date">📅 {{ new Date(event.date).toLocaleDateString('en-GB', { day: 'numeric', month: 'long', year: 'numeric' }) }}</p>
                </div>
                <p class="event-topic">{{ event.mainTopic }}</p>
                <button class="btn btn-primary" @click="viewEvent(event.id)">View Details</button>
              </div>
            </div>
          </div>
        </div>

        <button class="carousel-btn next" @click="nextSlide" v-if="events.length > 1">›</button>
      </div>

      <div class="carousel-dots" v-if="events.length > 1">
        <span 
          v-for="(event, index) in events" 
          :key="index"
          class="dot"
          :class="{ active: index === currentSlide }"
          @click="goToSlide(index)"
        ></span>
      </div>
    </div>

    <div v-else-if="loading" class="loading">Loading events...</div>
    <div v-else class="no-events">No events available at the moment.</div>

    <section class="info-section">
      <div class="info-grid">
        <div class="info-card">
          <h3>Network</h3>
          <p>Connect with the UK's most influential IT Leaders from leading organisations</p>
        </div>
        <div class="info-card">
          <h3>Learn</h3>
          <p>Share best practices and discuss upcoming challenges in technology</p>
        </div>
        <div class="info-card">
          <h3>Grow</h3>
          <p>Stay ahead in the rapidly evolving technology landscape</p>
        </div>
      </div>
    </section>
  </div>
</template>

<style scoped>
.homepage {
  width: 100%;
}

.hero-section {
  text-align: center;
  padding: 60px 20px;
  background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
  color: white;
}

.hero-section h1 {
  font-size: 48px;
  margin-bottom: 15px;
  font-weight: 700;
}

.subtitle {
  font-size: 20px;
  opacity: 0.95;
}

.carousel-container {
  max-width: 1200px;
  margin: 60px auto;
  padding: 0 20px;
}

.carousel {
  position: relative;
  overflow: hidden;
}

.carousel-slides {
  position: relative;
  width: 100%;
}

.carousel-slide {
  display: none;
  animation: fadeIn 0.5s;
}

.carousel-slide.active {
  display: block;
}

@keyframes fadeIn {
  from {
    opacity: 0;
  }
  to {
    opacity: 1;
  }
}

.event-card {
  display: grid;
  grid-template-columns: 1fr 1fr;
  gap: 40px;
  background: white;
  border-radius: 12px;
  overflow: hidden;
  box-shadow: 0 10px 30px rgba(0, 0, 0, 0.1);
}

.event-image {
  height: 400px;
  overflow: hidden;
}

.event-image img {
  width: 100%;
  height: 100%;
  object-fit: cover;
}

.event-content {
  padding: 40px;
  display: flex;
  flex-direction: column;
  justify-content: center;
}

.event-content h2 {
  font-size: 32px;
  color: #333;
  margin-bottom: 20px;
}

.event-info {
  margin-bottom: 20px;
}

.event-location,
.event-date {
  font-size: 16px;
  color: #666;
  margin: 8px 0;
}

.event-topic {
  font-size: 16px;
  color: #555;
  line-height: 1.6;
  margin-bottom: 30px;
}

.btn {
  padding: 15px 35px;
  border: none;
  border-radius: 4px;
  font-size: 16px;
  cursor: pointer;
  transition: all 0.3s ease;
  font-weight: 500;
  align-self: flex-start;
}

.btn-primary {
  background-color: #0066cc;
  color: white;
}

.btn-primary:hover {
  background-color: #0052a3;
}

.carousel-btn {
  position: absolute;
  top: 50%;
  transform: translateY(-50%);
  background: rgba(0, 0, 0, 0.5);
  color: white;
  border: none;
  width: 50px;
  height: 50px;
  border-radius: 50%;
  font-size: 30px;
  cursor: pointer;
  transition: background 0.3s ease;
  z-index: 10;
}

.carousel-btn:hover {
  background: rgba(0, 0, 0, 0.7);
}

.carousel-btn.prev {
  left: -60px;
}

.carousel-btn.next {
  right: -60px;
}

.carousel-dots {
  text-align: center;
  margin-top: 30px;
}

.dot {
  display: inline-block;
  width: 12px;
  height: 12px;
  border-radius: 50%;
  background: #ddd;
  margin: 0 5px;
  cursor: pointer;
  transition: background 0.3s ease;
}

.dot.active {
  background: #0066cc;
}

.info-section {
  max-width: 1200px;
  margin: 80px auto;
  padding: 0 20px;
}

.info-grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
  gap: 30px;
}

.info-card {
  text-align: center;
  padding: 40px 30px;
  background: #f8f9fa;
  border-radius: 8px;
}

.info-card h3 {
  font-size: 24px;
  color: #333;
  margin-bottom: 15px;
}

.info-card p {
  font-size: 16px;
  color: #666;
  line-height: 1.6;
}

.loading,
.no-events {
  text-align: center;
  padding: 60px 20px;
  font-size: 18px;
  color: #666;
}

@media (max-width: 768px) {
  .event-card {
    grid-template-columns: 1fr;
  }
  
  .event-image {
    height: 250px;
  }
  
  .carousel-btn.prev {
    left: 10px;
  }
  
  .carousel-btn.next {
    right: 10px;
  }
}
</style>
