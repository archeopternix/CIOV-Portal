<script setup>
import { ref, computed, onMounted } from 'vue'
import { useRoute } from 'vue-router'
import { marked } from 'marked'

const route = useRoute()
const eventData = ref(null)
const loading = ref(true)

const summaryContent = computed(() => {
  if (!eventData.value?.content) return ''
  const summaryMatch = eventData.value.content.match(/# Summary\n\n([\s\S]*?)(?=\n## |$)/)
  return summaryMatch ? summaryMatch[1].trim() : ''
})

const topicsList = computed(() => {
  if (!eventData.value?.content) return []
  const topicsMatch = eventData.value.content.match(/## Topics Covered\n\n([\s\S]*?)(?=\n## |$)/)
  if (!topicsMatch) return []
  
  const topicsText = topicsMatch[1].trim()
  return topicsText.split('\n')
    .filter(line => line.trim().startsWith('-'))
    .map(line => line.replace(/^-\s*/, '').trim())
})

onMounted(async () => {
  try {
    const eventId = route.params.id || 'cio-network-london-nov-2025'
    const response = await fetch(`/events/${eventId}.md`)
    const markdown = await response.text()
    
    const frontmatterRegex = /^---\n([\s\S]*?)\n---\n([\s\S]*)$/
    const match = markdown.match(frontmatterRegex)
    
    if (match) {
      const frontmatter = match[1]
      const content = match[2]
      
      const data = {}
      frontmatter.split('\n').forEach(line => {
        const [key, ...valueParts] = line.split(':')
        if (key && valueParts.length) {
          data[key.trim()] = valueParts.join(':').trim()
        }
      })
      
      eventData.value = { ...data, content }
    }
  } catch (error) {
    console.error('Error loading event:', error)
  } finally {
    loading.value = false
  }
})
</script>

<template>
  <div v-if="!loading && eventData">
    <!-- Hero Section -->
    <section class="hero">
      <div class="event-details">
        <h2>{{ eventData.location }}</h2>
        <p class="date">{{ new Date(eventData.date).toLocaleDateString('en-GB', { day: 'numeric', month: 'long', year: 'numeric' }) }}</p>
        <div class="cta-buttons">
          <button class="btn btn-primary">Request an invitation</button>
          <button class="btn btn-secondary">Book now</button>
        </div>
      </div>
    </section>

    <!-- Main Content -->
    <section class="content">
      <div class="intro">
        <p class="lead">{{ eventData.mainTopic }}</p>
      </div>

      <div class="summary-section">
        <h3>Summary</h3>
        <div class="summary-text" v-html="marked(summaryContent)"></div>
        <div class="feature-box">
          <strong>Time is maximised onsite through a combination of:</strong>
        </div>
      </div>

      <!-- Hotel Image -->
      <div class="hotel-section" v-if="eventData.hotelImage">
        <h3>Venue</h3>
        <img :src="eventData.hotelImage" :alt="eventData.location" class="hotel-image" />
      </div>

      <!-- Map -->
      <div class="map-section" v-if="eventData.mapUrl">
        <h3>Location</h3>
        <iframe 
          :src="eventData.mapUrl" 
          width="100%" 
          height="400" 
          style="border:0;" 
          allowfullscreen="" 
          loading="lazy" 
          referrerpolicy="no-referrer-when-downgrade">
        </iframe>
      </div>

      <!-- Topics Section -->
      <div class="topics-section" v-if="topicsList.length > 0">
        <h3>Topics<br>covered</h3>
        <ul class="topics-list">
          <li v-for="(topic, index) in topicsList" :key="index">{{ topic }}</li>
        </ul>
      </div>

      <!-- Bottom CTA -->
      <div class="bottom-cta">
        <h2>Request an invitation or book your place now</h2>
        <div class="cta-buttons">
          <button class="btn btn-primary">Request an invitation</button>
          <button class="btn btn-secondary">Book now</button>
        </div>
      </div>
    </section>
  </div>
  <div v-else-if="loading" class="loading">Loading event details...</div>
</template>

<style scoped>
.hero {
  text-align: center;
  padding: 40px 0;
}

.event-details h2 {
  font-size: 32px;
  color: #333;
  margin-bottom: 10px;
  font-weight: 300;
}

.date {
  font-size: 24px;
  color: #666;
  margin-bottom: 30px;
}

.cta-buttons {
  display: flex;
  gap: 15px;
  justify-content: center;
  flex-wrap: wrap;
}

.btn {
  padding: 15px 35px;
  border: none;
  border-radius: 4px;
  font-size: 16px;
  cursor: pointer;
  transition: all 0.3s ease;
  font-weight: 500;
}

.btn-primary {
  background-color: #0066cc;
  color: white;
}

.btn-primary:hover {
  background-color: #0052a3;
}

.btn-secondary {
  background-color: #28a745;
  color: white;
}

.btn-secondary:hover {
  background-color: #218838;
}

.content {
  margin-top: 40px;
}

.intro {
  margin-bottom: 40px;
}

.lead {
  font-size: 18px;
  line-height: 1.8;
  color: #555;
}

.summary-section {
  margin-bottom: 50px;
}

.summary-section h3 {
  font-size: 28px;
  margin-bottom: 20px;
  color: #333;
}

.summary-text {
  margin-bottom: 15px;
  font-size: 16px;
  color: #555;
  line-height: 1.8;
}

.summary-text :deep(p) {
  margin-bottom: 15px;
}

.feature-box {
  background-color: #f8f9fa;
  padding: 20px;
  border-left: 4px solid #0066cc;
  margin-top: 25px;
}

.hotel-section,
.map-section {
  margin-bottom: 50px;
}

.hotel-section h3,
.map-section h3 {
  font-size: 28px;
  margin-bottom: 20px;
  color: #333;
}

.hotel-image {
  width: 100%;
  max-width: 800px;
  height: auto;
  border-radius: 8px;
  box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
}

.topics-section {
  background-color: #f8f9fa;
  padding: 40px;
  border-radius: 8px;
  margin-bottom: 50px;
}

.topics-section h3 {
  font-size: 28px;
  margin-bottom: 25px;
  color: #333;
  line-height: 1.2;
}

.topics-list {
  list-style: none;
  padding-left: 0;
}

.topics-list li {
  padding: 12px 0;
  border-bottom: 1px solid #e0e0e0;
  font-size: 16px;
  color: #555;
  position: relative;
  padding-left: 25px;
}

.topics-list li:before {
  content: "▸";
  position: absolute;
  left: 0;
  color: #0066cc;
  font-weight: bold;
}

.topics-list li:last-child {
  border-bottom: none;
}

.bottom-cta {
  text-align: center;
  padding: 50px 0;
  background-color: #f8f9fa;
  border-radius: 8px;
  margin-bottom: 40px;
}

.bottom-cta h2 {
  font-size: 28px;
  margin-bottom: 30px;
  color: #333;
  font-weight: 400;
}

.loading {
  text-align: center;
  padding: 40px;
  font-size: 18px;
  color: #666;
}
</style>
