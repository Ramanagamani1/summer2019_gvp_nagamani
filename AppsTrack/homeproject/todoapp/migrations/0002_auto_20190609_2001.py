# Generated by Django 2.2.1 on 2019-06-09 14:31

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('todoapp', '0001_initial'),
    ]

    operations = [
        migrations.RenameField(
            model_name='todoitem',
            old_name='todolist',
            new_name='todolists',
        ),
    ]