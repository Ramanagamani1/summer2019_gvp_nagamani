from django.contrib import admin

# Register your models here.
from onlineapp.models import College,Student,MockTest1,Teacher

admin.site.register(College)

admin.site.register(Student)

admin.site.register(MockTest1)

admin.site.register(Teacher)