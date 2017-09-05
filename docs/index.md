---
layout: default
---

<section>
  {% for post in site.posts %}
  <ul>
    <li>
      <a href="{{ post.url }}">{{ post.title }}</a>
      {{ post.excerpt | remove: '<p>' | remove: '</p>' }}
    </li>
  </ul>
  {% endfor %}
 </section>
  
