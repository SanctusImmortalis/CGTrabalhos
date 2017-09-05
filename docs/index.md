---
layout: default
title: Site oficial dos projetos de CG de Nelson Guedes Barroca (AKA Sanctus Immortalis)
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
  
