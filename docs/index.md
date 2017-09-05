---
layout: default
---

<section>
  {% for post in site.posts %}
  <ul>
    <li>
      <a href="{{ site.url }}/CGTrabalhos{{ post.url }}">{{ post.title }}</a>
      {{ post.excerpt | remove: '<p>' | remove: '</p>' }}
    </li>
  </ul>
  {% endfor %}
 </section>
  
