from django.contrib import admin

# Register your models here.
from todoapp.models import todolist,todoitem

admin.site.register(todolist)


admin.site.register(todoitem)