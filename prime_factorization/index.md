---
publish: true
permalink: prime_factorization
title: Prime Factorization
code:
  - DuqFYy
usage:
  - https://leetcode.com/submissions/detail/388808430/

---
{% include_relative README.md %}
# Code

{% for x in page.code %}
```cpp
{% include_relative {{ x }}.cpp %}
```
# [Ideone it!](https://ideone.com/{{ x }})
{% endfor %}

{% for x in page.usage %}
{% if forloop.first %}
# Usage
{% endif %}
 - [Usage {{ forloop.index }}]({{x}})
{% endfor %}
