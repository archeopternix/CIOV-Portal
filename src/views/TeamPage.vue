<script setup>
import { ref } from 'vue'

const founder = {
  name: 'Reza Nazeman',
  title: 'Founder & CEO',
  bio: 'Reza & his Team connect Enterprise CIO\'s with Unicorn CEO\'s. After 20 years in corporate and four CIO roles (incl. Microsoft, KPMG, SAP & Bank of Scotland), Reza launched CIO Ventures, lifting synergies between Venture Capital and Technology Executives. Currently he is engaging with several ground braking ScaleUp CEO\'s, and more than 2000 CIOs globally, driving transformations within three core dimensions, fueled by the power of the largest international CIO relationship network.'
}

const partners = [
  {
    name: 'Scott Ely',
    image: 'https://img1.wsimg.com/isteam/ip/e7ef368e-7191-4c15-9311-bbb1425ed462/Scott%20Ely.jpeg/:/',
  },
  {
    name: 'Chas White',
    image: 'https://img1.wsimg.com/isteam/ip/e7ef368e-7191-4c15-9311-bbb1425ed462/Chas%20White.jpg/:/cr=t:0%25,l:0%25,w:100%25,h:100%25',
  },
  {
    name: 'Cory Klatt',
    image: 'https://img1.wsimg.com/isteam/ip/e7ef368e-7191-4c15-9311-bbb1425ed462/Cory%20Klatt-0001.jpg/:/',
    bio: 'Cory Klatt is a serial entrepreneur and CTO who has founded and grown several companies to successful exits.'
  },
  {
    name: 'Dan Spurling',
    image: 'https://img1.wsimg.com/isteam/ip/e7ef368e-7191-4c15-9311-bbb1425ed462/Dan%20Spurling-0001.jpg/:/cr=t:0%25,l:0%25,w:100%25,h:100%25',
  },
  {
    name: 'Rob Gray',
    image: 'https://img1.wsimg.com/isteam/ip/e7ef368e-7191-4c15-9311-bbb1425ed462/Rob%20Gray-0001.jpg/:/cr=t:0%25,l:0%25,w:100%25,h:100%25',
  },
  {
    name: 'Scott Ahlsmith',
    image: 'https://img1.wsimg.com/isteam/ip/e7ef368e-7191-4c15-9311-bbb1425ed462/Scott%20Ahlsmith-0001.jpeg/:/',
  },
  {
    name: 'Josh Hofstead',
    image: 'https://img1.wsimg.com/isteam/ip/e7ef368e-7191-4c15-9311-bbb1425ed462/Josh%20Hofstaed.jpg/:/cr=t:0%25,l:0%25,w:100%25,h:100%25',
  }
]
</script>

<template>
  <div class="team-page">
    <!-- Founder Section -->
    <section class="founder-section">
      <div class="founder-content">
        <h2>{{ founder.name }}, {{ founder.title }}</h2>
        <p class="founder-bio">{{ founder.bio }}</p>
      </div>
    </section>

    <!-- Executive Partner Network Section -->
    <section class="partners-section">
      <h2>Executive Partner Network</h2>
      
      <div class="partners-grid">
        <div 
          v-for="partner in partners" 
          :key="partner.name"
          class="partner-card"
        >
          <div class="partner-image-wrapper">
            <img :src="partner.image" :alt="partner.name" class="partner-image" />
          </div>
          <h3 class="partner-name">{{ partner.name }}</h3>
          <p v-if="partner.bio" class="partner-bio">{{ partner.bio }}</p>
        </div>
      </div>
    </section>

    <!-- Video Interview Section -->
    <section class="interview-section">
      <h2>Interview with Rajan Raghavan, CEO at The Fabric, Palo Alto</h2>
      <div class="video-container">
        <iframe 
          width="100%" 
          height="500" 
          src="https://www.youtube.com/embed/FMg-4OXvzKw" 
          title="The Fabric Spotlight: E27 | Symbiosis Between Enterprise CIO and Startup CEO" 
          frameborder="0" 
          allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
          allowfullscreen>
        </iframe>
      </div>
    </section>
  </div>
</template>

<style scoped>
.team-page {
  width: 100%;
}

.founder-section {
  background-color: #f8f9fa;
  padding: 60px 40px;
  margin-bottom: 60px;
}

.founder-content {
  max-width: 1000px;
  margin: 0 auto;
}

.founder-content h2 {
  font-size: 32px;
  color: #333;
  margin-bottom: 25px;
  font-weight: 600;
}

.founder-bio {
  font-size: 16px;
  line-height: 1.8;
  color: #555;
}

.partners-section {
  max-width: 1200px;
  margin: 0 auto 80px;
  padding: 0 20px;
}

.partners-section h2 {
  font-size: 36px;
  color: #333;
  margin-bottom: 50px;
  text-align: center;
  font-weight: 600;
}

.partners-grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
  gap: 40px;
  margin-bottom: 40px;
}

.partner-card {
  text-align: center;
  padding: 20px;
  transition: transform 0.3s ease;
}

.partner-card:hover {
  transform: translateY(-5px);
}

.partner-image-wrapper {
  width: 200px;
  height: 200px;
  margin: 0 auto 20px;
  border-radius: 50%;
  overflow: hidden;
  box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
}

.partner-image {
  width: 100%;
  height: 100%;
  object-fit: cover;
}

.partner-name {
  font-size: 20px;
  color: #333;
  margin-bottom: 10px;
  font-weight: 600;
}

.partner-bio {
  font-size: 15px;
  color: #666;
  line-height: 1.6;
  margin-top: 10px;
}

.interview-section {
  max-width: 1000px;
  margin: 0 auto 80px;
  padding: 0 20px;
}

.interview-section h2 {
  font-size: 28px;
  color: #333;
  margin-bottom: 30px;
  text-align: center;
  font-weight: 600;
}

.video-container {
  position: relative;
  width: 100%;
  padding-bottom: 56.25%;
  height: 0;
  overflow: hidden;
  border-radius: 8px;
  box-shadow: 0 4px 12px rgba(0, 0, 0, 0.15);
}

.video-container iframe {
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
}

@media (max-width: 768px) {
  .founder-section {
    padding: 40px 20px;
  }

  .founder-content h2 {
    font-size: 24px;
  }

  .partners-section h2 {
    font-size: 28px;
  }

  .partners-grid {
    grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
    gap: 30px;
  }

  .partner-image-wrapper {
    width: 150px;
    height: 150px;
  }
}
</style>
