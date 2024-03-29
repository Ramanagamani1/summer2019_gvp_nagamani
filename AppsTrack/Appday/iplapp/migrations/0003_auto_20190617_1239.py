# Generated by Django 2.2.1 on 2019-06-17 07:09

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('iplapp', '0002_auto_20190617_1211'),
    ]

    operations = [
        migrations.AddField(
            model_name='matches',
            name='match_id',
            field=models.CharField(default=1, max_length=128, unique=True),
            preserve_default=False,
        ),
        migrations.AlterField(
            model_name='deliveries',
            name='match',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='iplapp.Matches', to_field='match_id'),
        ),
    ]
