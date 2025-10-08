# Overview

This is a Vue 3 single-page application built with Vite that displays and manages technology events, specifically focused on CIO and IT leadership networking events. The application provides a browsable event catalog with detailed event pages, including location information, dates, and topics covered. Events are stored as Markdown files with frontmatter metadata, making content management simple and version-control friendly.

# User Preferences

Preferred communication style: Simple, everyday language.

# System Architecture

## Frontend Framework

**Technology**: Vue 3 with Composition API (`<script setup>` syntax)

**Build Tool**: Vite 7.x for fast development and optimized production builds

**Rationale**: Vue 3's Composition API provides better code organization and reusability. Vite offers instant server start and lightning-fast hot module replacement (HMR), significantly improving developer experience compared to traditional webpack-based setups.

## Routing Architecture

**Technology**: Vue Router 4.x with HTML5 history mode

**Routes**:
- `/` - Home page displaying event listings
- `/event/:id` - Dynamic event detail pages

**Rationale**: Client-side routing provides a seamless single-page application experience. HTML5 history mode creates clean URLs without hash fragments, improving SEO and user experience.

## Content Management Strategy

**Approach**: File-based content using Markdown with YAML frontmatter

**Location**: `/public/events/*.md`

**Metadata Structure**:
- `id` - Unique event identifier
- `title` - Event name
- `location` - Venue and city
- `date` - Event date (YYYY-MM-DD format)
- `time` - Start time
- `mainTopic` - Brief event description
- `hotelImage` - Featured image URL
- `mapUrl` - Embedded Google Maps URL

**Content Processor**: `marked` library (v16.x) for Markdown-to-HTML conversion

**Rationale**: Markdown files provide a non-technical way to manage event content. Frontmatter enables structured metadata while keeping content human-readable and git-friendly. This approach eliminates the need for a database for static content.

**Alternatives Considered**: CMS platforms like Strapi or headless CMS solutions would add unnecessary complexity for what is essentially static content with infrequent updates.

**Pros**: 
- Simple content editing workflow
- Version control for content changes
- No database required
- Fast page loads (static assets)

**Cons**:
- Dynamic content requires rebuild/reload
- Not suitable for user-generated content
- Limited querying capabilities

## Styling Approach

**Technology**: Vanilla CSS with CSS custom properties

**Strategy**: Global stylesheet with system font stack for optimal performance

**Rationale**: For a relatively simple application, vanilla CSS avoids the overhead of CSS-in-JS or heavy frameworks. System fonts provide excellent performance and native appearance across platforms.

## Development Server Configuration

**Host**: Configured to listen on all network interfaces (`host: true`)

**Port**: 5000

**Allowed Hosts**: Configured for Replit deployment environment

**Rationale**: These settings ensure the application works correctly in Replit's containerized environment while remaining accessible for development.

# External Dependencies

## Core Runtime Dependencies

**Vue 3** (v3.5.22): Progressive JavaScript framework for building user interfaces

**Vue Router 4** (v4.5.1): Official routing library for Vue.js single-page applications

**Marked** (v16.4.0): Markdown parser and compiler for converting event content to HTML

## Development Dependencies

**Vite** (v7.1.7): Next-generation frontend build tool and development server

**@vitejs/plugin-vue** (v6.0.1): Official Vite plugin for Vue 3 single-file component support

## Third-Party Services

**Google Maps Embed API**: Used for displaying event location maps via iframe embeds

**Unsplash**: External image hosting for hotel/venue photographs (based on image URLs in event files)

## Browser APIs

**HTML5 History API**: Used by Vue Router for clean URL navigation without page reloads