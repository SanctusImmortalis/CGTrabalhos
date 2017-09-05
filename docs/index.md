---
layout: default
---

<section>
  {% for post in site.posts %}
  <ul>
    <li>
      <a href="{{ post.url }}">{{ post.title }}</a>
      <br>{{ post.excerpt }}
    </li>
  </ul>
 </section>
  
