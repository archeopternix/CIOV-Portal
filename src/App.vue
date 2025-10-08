<script setup>
</script>

<template>
  <div class="container">
    <!-- Header Section -->
    <header class="header">
      <div class="logo">
        <img src="/logo.png" alt="Logo" />
      </div>
      <nav class="nav-menu">
        <a href="#events">Events</a>
        <a href="#team">Team</a>
        <a href="#sponsors">Sponsors</a>
        <a href="#contact">Contact</a>
      </nav>
    </header>

    <!-- Hero Section -->
    <section class="hero">
      <div class="event-details">
        <h2>Hilton Canary Wharf,<br>Central London, UK</h2>
        <p class="date">25 November, 2025</p>
        <div class="cta-buttons">
          <button class="btn btn-primary">Request an invitation</button>
          <button class="btn btn-secondary">Book now</button>
        </div>
      </div>
    </section>

    <!-- Main Content -->
    <section class="content">
      <div class="intro">
        <p class="lead">
          The UK CIO Network gathers the UK's most influential IT Leaders from the UK's largest organisations to network, share best practice and discuss the upcoming challenges and opportunities arising from the latest technology in a private, closed door environment.
        </p>
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
</template>

<style scoped>
* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}

.container {
  max-width: 1200px;
  margin: 0 auto;
  padding: 20px;
  font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, sans-serif;
  color: #333;
  line-height: 1.6;
}

.header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 20px 0;
  border-bottom: 1px solid #e0e0e0;
  margin-bottom: 30px;
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
}

.nav-menu a:hover {
  color: #0066cc;
}

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
</style>
