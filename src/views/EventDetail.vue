<script setup>
import { ref, onMounted } from 'vue'
import { useRoute } from 'vue-router'

const route = useRoute()
const eventData = ref(null)
const loading = ref(true)

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
        <p>
          The pace of change in IT has long been a challenge for anyone responsible for delivering quality services, resulting in a need for fundamental change in the way business operates and the way IT supports it.
        </p>
        <p>
          There is a clear divergence between companies that are adopting innovative technologies and those with encumbering legacy systems.
        </p>
        <p>
          The most effective transformation heads are leading their organisations into an agile technology age, quickly adapting and spearheading innovation across the business. The most successful businesses are tackling technology adoption, interconnectivity, implementation and company culture.
        </p>
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
      <div class="topics-section">
        <h3>Topics<br>covered</h3>
        <ul class="topics-list">
          <li>Investigating how to effectively prove the business value of your team</li>
          <li>How to lead in innovation with budget cuts</li>
          <li>Risks and resolutions in cyber security</li>
          <li>Overcoming the challenges of your legacy systems and incorporating new technology</li>
          <li>Applying AI and innovative tools across your business models</li>
          <li>Transforming customer experience through predictive analytics and technological transformation</li>
          <li>How you can plug the skill gap in an undersupplied market</li>
          <li>The CIO's role of educating the business</li>
          <li>Managing company culture and developing skills in a time of technology transformation</li>
          <li>Investigating the impact the cloud, AI and process automation is having on your business</li>
          <li>How to maximise the immediate through IT, while maintaining agility for the future</li>
          <li>Tool selection in an over saturated market, for the long and short-term</li>
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

.summary-section p {
  margin-bottom: 15px;
  font-size: 16px;
  color: #555;
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
