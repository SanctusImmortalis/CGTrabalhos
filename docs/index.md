---
layout: default
---

<section>
  <h1> Posts:</h1>
  <br>
  {% for post in site.posts %}
  <ul>
    <li>
      <b><a href="{{ site.url }}/CGTrabalhos{{ post.url }}">{{ post.title }}</a></b>
      <br>{{ post.excerpt | remove: '<p>' | remove: '</p>' }}
      <br><a href="{{ site.url }}/CGTrabalhos{{ post.url }}">Read more</a>
    </li>
  </ul>
  {% endfor %}
 </section>
  
