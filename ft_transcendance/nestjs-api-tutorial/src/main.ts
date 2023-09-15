import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import { ValidationPipe } from '@nestjs/common';

async function bootstrap() {
  const app = await NestFactory.create(AppModule);
//   Permet l'utilisation de Validation pipe (telecharger avec npm au préalable)
  app.useGlobalPipes(new ValidationPipe({
	whitelist: true, 
	// whitelist permet de ne recevoir que les champs que nous avons definie (email, password)
  }));
  await app.listen(3333);
}
bootstrap();
